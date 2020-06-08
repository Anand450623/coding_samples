/*============================================================================
 * Problem : Implement solution for lowest common ancestor in binary search tree.
 * Link    : https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{

	int data;
	Node *left;
	Node *right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}

}Node;

Node* insert(Node* root, int data)
{

	if(root == NULL)
	{
		return new Node(data);
	}
	else
	{
		Node* cur;
		if(data <= root->data)
		{
			cur = insert(root->left, data);
			root->left = cur;
		}
		else
		{
			cur = insert(root->right, data);
			root->right = cur;
		}

	   return root;
   }

}


Node *lca(Node *root, int v1,int v2)
{
	if(root==nullptr)
		return nullptr;
	if(root->data == v1 || root->data == v2)
		return root;

	Node* left = lca(root->left, v1, v2);
	Node* right = lca(root->right, v1, v2);

	if(left!=nullptr && right!=nullptr)
		return root;
	else
		return (left!=nullptr)?left:right;

}

int main()
{

	int data[] = {4,2,3,1,7,6};
	Node* root = NULL;

	int arr_len = sizeof(data)/sizeof(data[0]);
	for(int i=0;i<arr_len;i++)
		root = insert(root,data[i]);

	int v1=1, v2=7;

	Node* ancestor = lca(root,v1,v2);
	if(ancestor==nullptr)
		cout<<"Data not found"<<endl;
	else
		cout<<"The lowest common ancestor for v1 and v2 is = "<<ancestor->data<<endl;

	return 0;

}
