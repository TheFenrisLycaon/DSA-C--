// C++ program for diagonal
// traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;

// Tree node
struct Node
{
	int data;
	Node *left, *right;
};

void diagonalPrintUtil(Node* root, int d,map<int, vector<int>> &diagonalPrint)				
{
	// Base case
	if (!root)
		return;

	// Store all nodes of same
	// line together as a vector
	diagonalPrint[d].push_back(root->data);

	// Increase the vertical
	// distance if left child
	diagonalPrintUtil(root->left,d + 1, diagonalPrint);
	
	diagonalPrintUtil(root->right,d, diagonalPrint);
						
}

void diagonalPrint(Node* root)
{	
	map<int, vector<int> > diagonalPrint;
	diagonalPrintUtil(root, 0, diagonalPrint);

	cout << "Diagonal Traversal of binary tree : \n";
	for (auto it :diagonalPrint)
	{
		vector<int> v=it.second;
		for(auto it:v)
		cout<<it<<" ";
		cout<<endl;
	}
}

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);

	diagonalPrint(root);

	return 0;
}
