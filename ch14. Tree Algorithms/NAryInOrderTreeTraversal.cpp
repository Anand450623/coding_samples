/*============================================================================
 * Problem : Implement n-ary Tree traversal and sub-node count using dfs algorithm.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
	int data;
	vector<Node *> child;
}Node;

Node* createNode(int data)
{
	Node* obj = new Node;
	obj->data=data;
	return obj;
}

void inOrder(Node *node)
{

	size_t childCount = node->child.size();
	if(childCount==0)
	{
		cout<<node->data<<" ";
		return;
	}

	//left child
	for(size_t i=0;i<childCount-1;i++)
		inOrder(node->child[i]);

	//current node data
	cout<<node->data<<" ";

	//right node data
	inOrder(node->child[childCount-1]);

}

int main()
{

	Node *root = createNode(1);
	(root->child).push_back(createNode(2));
	(root->child).push_back(createNode(3));
	(root->child).push_back(createNode(4));

	(root->child[0]->child).push_back(createNode(5));
	(root->child[0]->child).push_back(createNode(6));

	(root->child[2]->child).push_back(createNode(7));

	(root->child[0]->child[1]->child).push_back(createNode(8));

	inOrder(root);

}
