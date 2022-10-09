#include<bits/stdc++.h>
using namespace std;
vector<int>v;// to store the left view
//structure of node
struct Node
{
    int data;
    struct Node *left, *right;// left and right pointer
};

//creation of new Node
Node *newNode(int data)
{
    Node *temp = new Node();// create new Node
    temp->data = data;
    temp->left = temp->right = NULL;//assign NUll to both left and right pointer
    return temp;// return the updated node.
}
// fucntion to calculate the Left view 
// we have to print the very left first node on every level
// starting with root being level 0 and below 1 and so on
void leftview(Node *node,int level)// pass the Node along with level
{
    if(node == NULL)return;
    // if level and vector size are same that means
    // we haven't visited that node.
    // First push the root as it the first view
    if(level == v.size())
    {
        v.push_back(node->data);
    }
    // traverse the left subtree as we have to print only the leftmost nodes
    // recursion to traverse and check if the level matches the size then push.
    // increment the levels as we go down
    leftview(node->left,level+1);// left traversal
    leftview(node->right,level+1);//right traversal.
}
int main()
{
    //create the tree structure nodes
    Node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right =  newNode(8);
    root->right->left = newNode(12);
    root->right->right= newNode(15);
    root->right->right->left = newNode(14);

    leftview(root,0);

    //display the vector having left view 
    for(auto i: v){
        cout<<i<<" ";
    }
    return 0;

}