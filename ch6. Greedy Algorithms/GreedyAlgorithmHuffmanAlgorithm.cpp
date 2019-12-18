/*
 * Problem: Given a input string, construct an optimal code for compression of given string.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int freq;
	char token;
	struct node *left,*right;
}node;

typedef struct minheap
{
	int size;
	int capacity;
	node ** array;
}minheap;

node* newNode(int freq,char token)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->freq=freq;
	newNode->token=token;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

minheap* newMinHeap(int capacity)
{
	minheap* newMinHeap = (minheap*)malloc(sizeof(minheap));
	newMinHeap->size=0;
	newMinHeap->capacity=capacity;
	newMinHeap->array = (node**)malloc(sizeof(node*)*capacity);
	return newMinHeap;
}

void swapMinNode(node** a, node **b)
{
	node *temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(minheap *minheap,int minimum_index)
{

	int smallest = minimum_index;
	int left = (2*smallest)+1;
	int right = (2*smallest)+2;

	if(left<minheap->size && minheap->array[left]->freq<minheap->array[smallest]->freq)
		smallest = left;
	if(right<minheap->size && minheap->array[right]->freq<minheap->array[smallest]->freq)
			smallest = right;

	if(minimum_index!=smallest)
	{
		swapMinNode(&minheap->array[minimum_index],&minheap->array[smallest]);
		minHeapify(minheap,smallest);
	}

}

bool isSizeOne(minheap *mheap)
{
	return (mheap->size==1);
}

node* extractMin(minheap *mheap)
{
	mheap->size--;
	node* smallest = mheap->array[0];
	mheap->array[0]= mheap->array[mheap->size];
	minHeapify(mheap,0);
	return smallest;
}

void insertNewNode(minheap *mheap, node* node)
{

	mheap->size++;
	int last_element_index = (mheap->size)-1;
	int parent_index = (last_element_index-1)/2;
	while(last_element_index && node->freq<mheap->array[parent_index]->freq)
	{
		mheap->array[last_element_index] = mheap->array[parent_index];
		last_element_index = parent_index;
		parent_index = (parent_index-1)/2;
	}

	mheap->array[last_element_index] = node;

}

void buildMinHeap(minheap *mheap)
{
	int n = mheap->size-1;

	for(int i=((n-1)/2);i>=0;i--)
		minHeapify(mheap,i);
}

bool isLeaf(node* root)
{
	return (root->left==NULL && root->right==NULL);
}

minheap* createAndBuildMinHeap(map<char,int> map,int size)
{

	minheap* mheap = newMinHeap(size);

	int index = 0;
	for(auto i:map)
	{
		mheap->array[index++] =  newNode(i.second,i.first);
	}

	mheap->size=size;
	buildMinHeap(mheap);

	return mheap;

}

node* createHuffmanTree(map<char,int> map,int size)
{
	node *left,*right,*top;

	minheap* mheap = createAndBuildMinHeap(map,size);

	while(!isSizeOne(mheap))
	{
		left = extractMin(mheap);
		right = extractMin(mheap);
		top = newNode(left->freq+right->freq,'$');
		top->left=left;
		top->right=right;
		insertNewNode(mheap,top);
	}

	return extractMin(mheap);

}

void printCodes(node *root,int arr[],int top)
{

	if(root->left)
	{
		arr[top] = 0;
		printCodes(root->left,arr,top+1);
	}
	if(root->right)
	{
		arr[top] = 1;
		printCodes(root->right,arr,top+1);
	}

	if(isLeaf(root))
	{
		cout<<root->token<<" : ";
		for(int i=0;i<top;i++)
			cout<<arr[i];
		cout<<endl;
	}

}

void HuffmanCode(map<char,int> map, int size)
{
	node* root = createHuffmanTree(map,size);
	int arr[100],top=0; // 100 should be replaced by height by tree
	printCodes(root,arr,top);
}

int main()
{

	string input = "AABACDACA";
	map<char,int> map;

	vector<char> keys;
	vector<int> values;

	for(auto i:input)
	{
		if(map.count(i))
			map[i] += 1;
		else
			map[i] = 1;
	}

	HuffmanCode(map,map.size());

	return 0;

}
