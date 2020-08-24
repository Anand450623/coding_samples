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

void update(node* root, int index, int data, int left, int right)
{

	if(right<index || left>index)
		return;

	if(left == index && index == right)
	{
		root->value = data;
		return;
	}

	int mid = left - (left-right)/2;
	int sum1 = 0;
	int sum2 = 0;
	if(index <= mid)
	{

		if(root->left==NULL)
			root->left = createNode(0);

		update(root->left, index, data, left, mid);

	}
	else
	{

		if(root->right==NULL)
			root->right = createNode(0);

		update(root->right, index, data, mid+1, right);

	}

	if(root->left)
		sum1 = root->left->value;

	if(root->right)
		sum2 = root->right->value;

//	cout<<index<<" "<<left<<" "<<right<<" "<<root->value<<" "<<left<<" "<<mid<<" "<<sum1<<" "<<mid+1<<" "<<right<<" "<<sum2<<endl;

	root->value = sum1+sum2;
	return;

}

int range_sum(node* root, int start, int end, int min, int max)
{

	if(root == NULL)
		return 0;

	if(start>max || end<min)
		return 0;

	if(start<=min && max<=end)
		return root->value;

	int mid = min - (min-max)/2;

//	cout<<start<<" "<<end<<" "<<min<<" "<<mid<<" "<<max<<endl;

	return range_sum(root->left, start, end, min, mid) + range_sum(root->right, start, end, mid+1, max);

}

void traversal(node *root)
{
	if(root == NULL)
		return;
	traversal(root->left);
	cout<<root->value<<" ";
	traversal(root->right);
}

int main()
{

	int n = 10;

	node* root = createNode(0);
	update(root, 0, 10, 0, n-1);

	cout<<"Tree elements = ";
	traversal(root);
	cout<<"\n*******************************************************\n";

	update(root, 5, 2, 0, n-1);

	cout<<"Tree elements = ";
	traversal(root);
	cout<<"\n*******************************************************\n";

	cout<<"Range Sum for range[0-4] = "<<range_sum(root, 0, 4, 0, n-1)<<endl;
	cout<<"Range Sum for range[2-9] = "<<range_sum(root, 2, 9, 0, n-1)<<endl;
	cout<<"Range Sum for range[0-5] = "<<range_sum(root, 0, 5, 0, n-1)<<endl;

	return 0;

}
