/*============================================================================
 * Problem : Finding height of a binary tree
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{

	int data;
	struct Node* right;
	struct Node* left;

}Node;

Node* createNode(int data)
{
	Node* node = new Node;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int findHeight(Node* node)
{

	if(node==NULL)
		return 0;

	int lHeight = findHeight(node->left);
	int rHeight = findHeight(node->right);

	return max(lHeight,rHeight)+1;

}

int main()
{

	Node* head = createNode(1);

	head->left = createNode(2);
	head->right = createNode(3);

	head->left->left = createNode(4);
	head->left->right = createNode(5);

	head->left->right->left = createNode(6);
	head->left->right->right = createNode(7);

	head->left->right->right->left = createNode(8);
	head->left->right->right->right = createNode(9);

	head->right->left = createNode(10);
	head->right->right = createNode(11);

	head->right->right->left = createNode(12);
	head->right->right->right = createNode(13);

	cout<<"The height of the tree is = "<<findHeight(head);

	return 0;

}
