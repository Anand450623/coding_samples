/*============================================================================
 * Problem : Implement various traversal techniques for a binary tree.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int data)
{
	Node* temp = new Node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void preOrder(Node* node)
{

	if(node==NULL)
		return;

	cout<<node->data<<" ";
	preOrder(node->left);
	preOrder(node->right);

}

void postOrder(Node* node)
{

	if(node==NULL)
		return;

	postOrder(node->left);
	postOrder(node->right);
	cout<<node->data<<" ";

}

void InOrder(Node* node)
{

	if(node==NULL)
		return;

	InOrder(node->left);
	cout<<node->data<<" ";
	InOrder(node->right);

}

int main()
{

	Node* head = createNode(1);

	head->left = createNode(2);
	head->right = createNode(3);

	head->left->left = createNode(4);
	head->left->right = createNode(5);
	head->left->right->left = createNode(6);

	head->right->right = createNode(7);

	cout<<"Pre-order traversal for the above tree is given by = ";
	preOrder(head);
	cout<<endl<<endl;

	cout<<"In-order traversal for the above tree is given by = ";
	InOrder(head);
	cout<<endl<<endl;

	cout<<"Post-order traversal for the above tree is given by = ";
	postOrder(head);
	cout<<endl<<endl;

	return 0;

}
