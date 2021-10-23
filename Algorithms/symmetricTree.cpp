#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};

bool recur(Node* left, Node* right){
    if(left==NULL and right==NULL){
        return true;
    }
    if(left and right and left->key==right->key){
        recur(left->left, right->right);
        recur(left->right, right->left);
    }
    return false;
}


bool isSymmetricRecur(Node* root) {
    return recur(root, root);
}

bool isSymmetricIter(Node* root) {
    if(!root || !root->left and !root->right){
        return true;
    }

    queue<Node*> q;
    q.push(root);
    q.push(root);
    while(!q.empty()){
        Node* left = q.front();
        q.pop();
        Node* right = q.front();
        q.pop();

        if(left->key != right->key){
            return false;
        }

        if(left->left and right->right){
            q.push(left->left);
            q.push(right->right);
        }
        else if(!left->left or !right->right){
            return false;
        }

        if(left->right and right->left){
            q.push(left->right);
            q.push(right->left);
        }
        else if(!left->right or !right->left){
            return false;
        }

    }
    return true;

}