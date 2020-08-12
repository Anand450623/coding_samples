/*============================================================================
 * Problem   : Implement trie data structure
 * Reference : GeeksForGeeks
 * Author    : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
#define ALPHABET_CONST 26
using namespace std;

typedef struct trie
{
	struct trie *child[ALPHABET_CONST];
	bool isEndNode;
}trie;

trie* createNewTrie()
{
	trie* newNode = new trie();
	for(int i=0; i<ALPHABET_CONST; i++)
		newNode->child[i] = NULL;
	newNode->isEndNode=false;
	return newNode;
}

void insertIntoTrie(trie* root, string data)
{
	trie* temp = root;
	for(unsigned int i=0; i<data.length(); i++)
	{
		int index = data[i]-'a';
		if(temp->child[index] == NULL)
			temp->child[index] = createNewTrie();
		temp = temp->child[index];
	}
	temp->isEndNode = true;
}

bool search(trie* root, string data)
{

	if(root == NULL)
		return false;

	trie* temp = root;
	for(unsigned int i=0; i<data.length(); i++)
	{
		int index = data[i]-'a';
		if(temp->child[index] == NULL)
			return false;
		temp = temp->child[index];
	}

	return temp->isEndNode;

}

bool isEmpty(trie* root)
{
	for(int i=0; i<ALPHABET_CONST; i++)
		if(root->child[i] != NULL)
			return false;
	return true;
}

trie* remove(trie* root, string key, unsigned int depth = 0)
{

	if(root == NULL)
		return NULL;

	if(depth == key.length())
	{
		if(root->isEndNode)
			root->isEndNode = false;
		if(isEmpty(root))
		{
			delete(root);
			root = NULL;
		}
		return root;
	}

	int index = key[depth]-'a';
	root->child[index] = remove(root->child[index], key, depth+1);

	if(root->isEndNode == false && isEmpty(root))
	{
		delete(root);
		root = NULL;
	}

	return root;

}

void display(trie* root, int index, char str[])
{

	if(root==NULL || root->isEndNode)
	{
		for(int i=0; i<index; i++)
			cout<<str[i];
		cout<<endl;
	}

	for(int i=0; i<ALPHABET_CONST; i++)
	{
		if(root->child[i] != NULL)
		{
			str[index] = 'a'+i;
			display(root->child[i], index+1, str);
		}
	}

}

int main()
{

	string keys[] = { "the", "a", "there",
					  "answer", "any", "by",
					  "bye", "their", "hero", "heroplane" };

	int n = sizeof(keys)/sizeof(keys[0]);
	trie *root = createNewTrie();

	for (int i = 0; i < n; i++)
		insertIntoTrie(root, keys[i]);

	char str[20];
	int level = 0;
	//displaying content of trie before any operation
	display(root, level, str);

	cout<<"Search result for the in trie yielded = ";
	search(root, "the")? cout << "Yes\n" : cout << "No\n";
	cout<<"Search result for these in trie yielded = ";
	search(root, "these")? cout << "Yes\n" : cout << "No\n";

	//removing keyword heroplane from trie
	remove(root, "heroplane");

	//displaying content of trie before after deletion
	display(root, 0, str);

	cout<<"Search result for hero in trie yielded = ";
	search(root, "hero") ? cout << "Yes\n" : cout << "No\n";

	return 0;

}
