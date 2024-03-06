#include<bits/stdc++.h>
using namespace std;
// structure of node
struct Node
{
    Node *left; //left pointer
    Node *right;//right pointer
    int data;
    int line;//line denotes the line number 0 for root 
    //left side of root starts with negative line numbers
    //right side of root starts with positive line numbers
};
//creation of new Node
Node* newNode(int data)
{
    Node* node = new Node();
    node->left = node->right = NULL;//assign NUll to both left and right pointer
    node->data = data;//assign the value to the data field
    return node;//return the node.
}
// this function identifies the nodes present at the top 
void topView(Node *root)
{
    vector<int>ans;// vector to store the final view nodes

    if(root == NULL)return;
    // map to store the node with line number
    map<int,int> mp;
    //queue to store the Node and line number
    queue<pair<Node*,int>>q;
    q.push({root,0});//push the very first Node i.e. root.
    //traverse while the queue is not empty
    while(!q.empty()){
        auto it = q.front();//pointer to store the front of queue
        q.pop();// then pop the element
        // store the node and line in the  respective variables
        Node* node = it.first;
        int line = it.second;
        
        //if line not present in the map 
        //then add the line number with respective node.
        if(mp.find(line)==mp.end())
        {
            mp[line] = node->data;
        }

        //if line present the traverse the other nodes.

        //if left node present push the left node and decrement the line number
        if(node->left != NULL)q.push({node->left ,line-1});
        // if ritgh node present push the right node and increment the line number.
        if(node->right != NULL)q.push({node->right,line+1});

    }
    // display the value of map which contains the top view 
    cout<<"Top View of Tree is: ";
    for(auto i:mp)
    {
        cout<<i.second<<" ";
    }
}
int main()
{
    //create a tree with root and its childrens
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right= newNode(5);
    root->left->right->left = newNode(6);
    root->right->right= newNode(7);
    //call the function to calculate the top view.
    topView(root);
    return 0;
}