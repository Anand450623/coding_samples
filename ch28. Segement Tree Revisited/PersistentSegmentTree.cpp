/*
 * Problem   : Given an array of integers, implement a persistent segment tree which stores the information related to various updates in tree.
 * Reference : https://www.geeksforgeeks.org/persistent-segment-tree-set-1-introduction/
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int value;
	struct node* left;
	struct node* right;
}node;

node* createNode(int data)
{
	node* temp = new node;
	temp->value = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void traversal(node *root)
{
	if(root == NULL)
		return;
	traversal(root->left);
	cout<<root->value<<" ";
	traversal(root->right);
}

void build(int arr[], node* root, int min, int max)
{
	if(min==max)
	{
		root->value = arr[min];
		return;
	}
	int mid = min - (min-max)/2;
	root->left = createNode(0);
	root->right = createNode(0);
	build(arr, root->left, min, mid);
	build(arr, root->right, mid+1, max);
	root->value = root->left->value + root->right->value;
}

void update(node* old, node* curr, int index, int data, int low, int high)
{

	if(index<low || index>high || low>high)
		return;

	if(index==low && index==high)
	{
		curr->value = data;
		return;
	}

	int mid = low - (low-high)/2;
	int sum1=0, sum2=0;
	if(index <= mid)
	{
		curr->right = old->right;
		if(curr->left == NULL)
			curr->left = createNode(0);
		update(old->left, curr->left, index, data, low, mid);
	}
	else
	{
		curr->left = old->left;
		if(curr->right==NULL)
			curr->right = createNode(0);
		update(old->right, curr->right, index, data, mid+1, high);
	}

	if(curr->left)
		sum1 = curr->left->value;

	if(curr->right)
		sum2 = curr->right->value;

	curr->value = sum1+sum2;

}

int range_sum(node* root, int start, int end, int min, int max)
{

	if(start>max || end<min || min>max)
		return 0;
	if(start<= min && max<=end)
		return root->value;
	int mid = min - (min-max)/2;
	return range_sum(root->left, start, end, min, mid) + range_sum(root->right, start, end, mid+1, max);

}

int main()
{

	int arr[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	node* root = createNode(0);
	build(arr, root, 0, size-1);
	cout<<"Tree traversal for version 0 = ";
	traversal(root);
	cout<<endl;

	node* v1 = createNode(0);
	update(root, v1, 2, 10, 0, size-1);
	cout<<"Tree traversal for version 1 = ";
	traversal(v1);
	cout<<endl;

	node* version[10]; // support 10 versions
	version[0] = root;
	version[1] = v1;

	cout<<"Range sum[0-3] for v0 = "<<range_sum(version[0], 0, 3, 0, size-1)<<endl;
	cout<<"Range sum[0-3] for v1 = "<<range_sum(version[1], 0, 3, 0, size-1)<<endl;

	return 0;

}
