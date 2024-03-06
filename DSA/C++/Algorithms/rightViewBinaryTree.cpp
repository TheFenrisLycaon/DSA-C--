#include<bits/stdc++.h>
using namespace std;
vector<int> v;// vector to store the right view
//structure of node containing data and pointers
struct Node
{
    int data;
    struct Node *left, *right;// left and right pointer
};
// function to create a newNode
Node *newNode(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;// initialize NULL to both pointers
    return temp;// return the updated node.
}
// fucntion to calculate the right view 
// we have to print the very right last node on every level
// starting with root being level 0 and below 1 and so on
void rightView(Node *node,int level)//pass the node along with the level
{
    if(node == NULL)return;
    // if level and vector size are same that means
    // we haven't visited that node.
    // root gets pushed as its level is 0 and size of vector is 0
    if(level == v.size()){
        v.push_back(node->data);
    }
    // traverse the right side of tree as we have to print the rightmost node.
    // when we come to right node it is at level 1 and size of vector is also,
    //updated to level 1 so push the right node and so on
    rightView(node->right,level+1);//traverse the right node
    rightView(node->left,level+1);// traverse the left node.
}
int main()
{
    //create the nodes 
    Node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right =  newNode(8);
    root->right->left = newNode(12);
    root->right->right= newNode(15);
    root->right->left->left = newNode(5);

    rightView(root,0);// root being at level 0

    //display the vector containing the right view of the tree
    cout<<"Right View of Binary Tree is: ";
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}