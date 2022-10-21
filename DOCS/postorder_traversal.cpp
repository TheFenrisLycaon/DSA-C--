//Function to perform inorder Traversal of a Binary Tree

#include<bits/stdc++.h>
using namespace std;


//declaring a structure Node 
struct Node{
    int key;
    struct Node* left;
    struct Node* right;
};


//to allocate memory to newNode
struct Node* newNode(int x)
{
    struct Node* root = (struct Node*)malloc(sizeof(struct Node*));
    root->left = NULL;
    root->right = NULL;
    root->key = x;
    return root;
}

//function to perform inorder traversal of a Binary tree.
void postorder(struct Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";


    }
}

int main()
{
    //declaring root node and declaring branches of the tree.
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right = newNode(35);
    root->right->left = newNode(40);
    root->right->right = newNode(45);
    postorder(root);
    

    
    return 0;
}
