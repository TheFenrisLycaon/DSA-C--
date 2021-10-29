#include <bits/stdc++.h>
using namespace std;

struct Tree
{
	struct Tree *child[26];
	bool is_end;
	Tree()
	{
		memset(child, 0, sizeof(child));
		is_end = false;
	}
};

struct Tree *root;
//inserts a word to the Tree
void insert(string s)
{
	struct Tree *temp = root;
	//traverses over each character
	//if the character already exists then it simply iterates over
	//otherwise creates a new node and inserts the character
	for (char c : s)
	{
		if (!temp->child[c - 'a'])
			temp->child[c - 'a'] = new Tree;
		temp = temp->child[c - 'a'];
	}
	//sets the last letter's boolean value to true
	temp->is_end = true;
}
//returns true if the word exists, false otherwise
bool check(string s)
{
	struct Tree *temp = root;
	//iterates over the character of the word
	for (char c : s)
	{
		//if at any point the char of the word being check is not found it return false
		if (!temp->child[c - 'a'])
			return false;
		temp = temp->child[c - 'a'];
	}
	//returns the last letters boolean value
	return temp->is_end;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	root = new Tree;
	int n;
	cout << "Input the number of words in the List" << endl;
	cin >> n;
	string word;
	cout << "Enter the words" << endl;
	//words that are being inserted to Tree.
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		insert(word);
	}
	cout << "Enter the number of words you want to check exist in the List" << endl;
	int m;
	cin >> m;
	//the words to be checked
	for (int i = 0; i < m; i++)
	{
		cin >> word;
		if (check(word))
			cout << "This word exist in the list" << endl;
		else
			cout << "This word does not exist in the list" << endl;
	}
}
