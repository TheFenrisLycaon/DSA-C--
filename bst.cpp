#include <bits/stdc++.h>

struct Node
{
    int value;
    // The left node is always lesser than it's parent node
    // The right is always greater than it's parent node
    // Makes things like searching and balancing easier.
    Node *left;
    Node *right;
};

Node *generateNewNode(int x)
{
    // Generates a new node in heap.
    Node *newNode = new Node();
    newNode->value = x;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *insert(Node *current, int x)
{
    // Inserts a new node at the correct position according to sorting.

    // If no node is present, insert the root node
    if (current == NULL)
        current = generateNewNode(x);

    // If value to be inserted is greater than or equal to current value
    // Insert at right child
    else if (current->value <= x)
        current->right = insert(current->right, x);

    // If value to be inserted is smaller than current value
    // Insert at left child
    else
        current->left = insert(current->left, x);

    return current;
}

bool search(Node *current, int x)
{
    // Searches for an element in the tree
    // Since the tree is already sorted
    // We can use this to find the element more efficiently

    // If no node is present return false
    if (current == NULL)
        return false;

    // If value to be searched is on this node return true
    else if (x == current->value)
        return true;

    // If it is lesser than the node value search in left subtree
    else if (x < current->value)
        return search(current->left, x);

    // If it is greater than the node value search in right subtree
    else
        return search(current->right, x);
}

Node *findMin(Node *current)
{
    // Gives node with min value in the tree
    // Since this is a BST, the left child, if present, will always have lesser value than its parent
    // We check for the same by making recursive calls and finding the left-most node
    if (current->left == NULL)
        return current;
    else
        return findMin(current->left);
}

Node *findMax(Node *current)
{
    // Gives node with max value in th tree
    // Since this is a BST, the right child, if present, will always have greater value than its parent
    // We check for the same by making recursive calls and finding the right-most node
    if (current->right == NULL)
        return current;
    else
        return findMax(current->right);
}

int getMaxHeight(Node *current)
{
    // Gives the max height of tree
    // Height of a node is defined as the longest path from the node to a leaf node
    // Max height of a tree is the height of root
    // Depth of a node is defined as the num of edges in path from root to that node

    // returns -1 since height of leaf node is 0
    // -1 balances the +1 in the next step.
    if (current == NULL)
        return -1;

    // Get max from the height of left and right subtrees.
    return std::max(getMaxHeight(current->left), getMaxHeight(current->right)) + 1;
}

void levelOrder(Node *root)
{
    // Level order traversal is also known as breadth first traversal
    // We visit nodes level by level starting from root node.

    // If tree is empty, return to main
    if (root == NULL)
        return;

    // We first visit the root node at level 0
    // Then we go to the next level and find two nodes.
    // If we choose one node, we cannot visit the children of another node
    // Revisiting solves this problem but is not allowed since we have to visit a node only once
    // So, we need to store the pointers to the left out nodes and access them later
    // Notice that the pointers will be accessed in FIFO mode
    // Thus, queue is used and we push the root to queue.

    std::queue<Node *> Q;
    Q.push(root);

    // Repeat while Queue isn't empty
    while (!Q.empty())
    {
        Node *pos = Q.front();

        // Visit the element on the front node
        std::cout << pos->value << "|\t";

        // Keep checking if left or right node exists and push them in the queue
        if (pos->left != NULL)
            Q.push(pos->left);
        if (pos->right != NULL)
            Q.push(pos->right);

        // Pop the front element since it has already been visited.
        Q.pop();
    }
}

// The next three traversals are called depth-first traversal
// Visit all the node in a subtree before visiting the other subree

void preOrder(Node *current)
{
    // Goes in order of root -> left -> right ( P L R)
    // Visit a node, go to left, go to right

    // If tree is empty, return
    if (current == NULL)
        return;

    std::cout << current->value << "|\t"; // P
    preOrder(current->left);              // L
    preOrder(current->right);             // R
}

void postOrder(Node *current)
{
    // Goes in order of left -> right -> root ( L R P )
    // Go to left, go to right, visit the parent node

    // If tree is empty, return
    if (current == NULL)
        return;

    postOrder(current->left);             // L
    postOrder(current->right);            // R
    std::cout << current->value << "|\t"; // P
}

void inOrder(Node *current)
{
    // Goes in order of left -> root -> right ( L P R )
    // Go to left, visit the parent node, go to right

    // If tree is empty, return
    if (current == NULL)
        return;

    inOrder(current->left);               // L
    std::cout << current->value << "|\t"; // P
    inOrder(current->right);              // R
}

bool isLesser(Node *current, int parameter)
{
    // ! Expensive
    if (current == NULL)
        return true;

    if (current->value <= parameter && isLesser(current->left, parameter) && isLesser(current->right, parameter))
        return true;

    return false;
}

bool isGreater(Node *current, int parameter)
{
    //! Expensive
    if (current == NULL)
        return true;

    if (current->value >= parameter && isGreater(current->left, parameter) && isGreater(current->right, parameter))
        return true;

    return false;
}

bool isBinaryExpensive(Node *current)
{
    //! Here the functions isLesser and isGreater are very expensive since we look at all the values inside the tree.

    // If no children are present return
    if (current == NULL)
        return true;

    // Check if left and right subtrees are binary
    // Check if all the values in left sub are lesser than current and right sub are greater than current.
    // ! Even if any value in left is greater or any value in right is smaller,
    // ! the above two functions donot stop and execute anyway.
    if (isBinaryExpensive(current->left) && isBinaryExpensive(current->right) && isLesser(current->left, current->value) && isGreater(current->right, current->value))
        return true;

    return false;
}

bool isBinary(Node *current, int minVal, int maxVal)
{
    // Better Solution
    // Pass a min and max bounds for the value at the current node.
    // For 1st generation
    // The range is between -INF and INF
    // For 2nd generation
    // The range is between -INF, currentValue and currentValue, INF for left and right children.
    // For third generation nodes and forward,
    // The range is even lesser since they have to be b/w their parents and their grandparents.

    // If tree is empty, return
    if (current == NULL)
        return true;

    // Check if current node is b/w minVal and maxVal
    // Check for left tree and right tree
    if (current->value > minVal &&
        current->value < maxVal &&
        isBinary(current->left, minVal, current->value) &&
        isBinary(current->right, current->value, maxVal))
        return true;

    return false;
}

Node *deleteNode(Node *current, int data)
{
    // Deleting a node from a tree

    // If tree is empty, return
    if (current == NULL)
        return current;

    // Data is smaller, search in left subtree
    else if (current->value > data)
        current->left = deleteNode(current->left, data);

    // Data is greater, search in right subtree
    else if (current->value < data)
        current->right = deleteNode(current->right, data);

    // Found ya bruh. You're DEAD NOW !!!
    // Node to be deleted can have three cases.
    else
    {
        // Can have no child nodes
        // Just set the current node to null
        if (current->left == NULL && current->right == NULL)
        {
            delete current;
            current = NULL;
        }

        // Can have one child
        // Set the child node as current node and return
        // Left Only
        else if (current->left == NULL)
        {
            Node *temp = current;
            current = current->left;
            delete temp;
        }

        // Can have one child
        // Set the child node as current node and return
        // Right Only
        else if (current->right == NULL)
        {
            Node *temp = current;
            current = current->right;
            delete temp;
        }

        // Can have both children
        // Find the min value in the right side and replace with node to be deleted
        else
        {
            Node *temp = findMin(current->right);
            current->value = temp->value;
            current->right = deleteNode(current->right, temp->value);
        }
    }

    return current;
}

int main()
{
    Node *ROOT = NULL;
    ROOT = insert(ROOT, 15);
    ROOT = insert(ROOT, 10);
    ROOT = insert(ROOT, 20);
    ROOT = insert(ROOT, 8);
    ROOT = insert(ROOT, 12);
    ROOT = insert(ROOT, 17);
    ROOT = insert(ROOT, 25);

    // Searching
    std::cout << search(ROOT, 8) << std::endl;
    std::cout << search(ROOT, 10) << std::endl;

    // Finding Min and Max
    std::cout << findMax(ROOT)->value << std::endl;
    std::cout << findMin(ROOT)->value << std::endl;

    // Getting Height
    std::cout << getMaxHeight(ROOT) << std::endl;

    // Traversal
    levelOrder(ROOT);
    std::cout << std::endl;
    preOrder(ROOT);
    std::cout << std::endl;
    inOrder(ROOT);
    std::cout << std::endl;
    postOrder(ROOT);
    std::cout << std::endl;

    // Checking Binary Search
    std::cout << isBinary(ROOT, INT_MIN, INT_MAX) << std::endl;
    std::cout << isBinaryExpensive(ROOT) << std::endl;

    // Deletion
    deleteNode(ROOT, 8);
    preOrder(ROOT);
    std::cout << std::endl;
    deleteNode(ROOT, 20);
    preOrder(ROOT);
    std::cout << std::endl;

    return 0;
}
