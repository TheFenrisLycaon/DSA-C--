#include <bits/stdc++.h>

struct Node
{
	int data;
	Node *left, *right;
};

Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

bool findPath(Node *root, std ::vector<int> &path, int data)
{
	if (root == NULL)
		return false;

	path.push_back(root->data);

	if (root->data == data)
		return true;

	if ((root->left && findPath(root->left, path, data)) ||
		(root->right && findPath(root->right, path, data)))
		return true;

	path.pop_back();
	return false;
}

int findLCA(Node *root, int n1, int n2)
{
	std ::vector<int> path1, path2;

	if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
		return -1;

	int i;
	for (i = 0; i < path1.size() && i < path2.size(); i++)
	{
		if (path1[i] != path2[i])
			break;
	}
	return path1[i - 1];
}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->right->right = newNode(8);
	root->right->right->left = newNode(9);
	std ::cout << "LCA(2, 3) = " << findLCA(root, 2, 3) << std ::endl;
	std ::cout << "LCA(6, 9) = " << findLCA(root, 6, 9) << std ::endl;
	std ::cout << "LCA(8, 4) = " << findLCA(root, 8, 4) << std ::endl;
	std ::cout << "LCA(8, 9) = " << findLCA(root, 8, 9) << std ::endl;
	return 0;
}