#include <bits/stdc++.h>

struct Node
{
    int value;
    // The left node is always lesser than it's parent node
    // The right is always greater than it's parent node
    // Makes things like searching and sorting easier.
    Node *left;
    Node *right;
};

Node *generateNewNode(int x)
{
    Node *newNode = new Node();
    newNode->value = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int x)
{
    if (root == NULL)
    {
        root = generateNewNode(x);
    }
    else if (root->value < x)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left, x);
    return root;
}

bool search(Node *root, int x)
{
    if (root == NULL)
        return false;
    else if (x == root->value)
        return true;
    else if (x < root->value)
        return search(root->left, x);
    else
        return search(root->right, x);
}

int findMin(Node *root)
{
    // Gives min value of leaf node.x
    if (root->left == NULL)
        return root->value;
    else
        return findMin(root->left);
}

int findMax(Node *root)
{
    // Node *pos = root;
    if (root->right == NULL)
        return root->value;
    else
        return findMax(root->right);
}

int getHeight(Node *root)
{
    if (root == NULL)
        return -1;
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    std::queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *pos = Q.front();
        std::cout << pos->value << "|\t";
        if (pos->left != NULL)
            Q.push(pos->left);
        if (pos->right != NULL)
            Q.push(pos->right);
        Q.pop();
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    std::cout << root->value << "|\t";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->value << "|\t";
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    std::cout << root->value << "|\t";
    inOrder(root->right);
}

bool isLesser(Node *root, int parameter)
{
    // ! Expensive
    if (root == NULL)
        return true;
    if (root->value <= parameter && isLesser(root->left, parameter) && isLesser(root->right, parameter))
        return true;
    return false;
}

bool isGreater(Node *root, int parameter)
{
    //! Expensive
    if (root == NULL)
        return true;
    if (root->value >= parameter && isGreater(root->left, parameter) && isGreater(root->right, parameter))
        return true;
    return false;
}

bool isBinaryExpensive(Node *root)
{
    //! Here the functions isLesser and isGreater are very expensive since we look at all the values inside the tree.
    if (root == NULL)
        return true;
    if (isBinaryExpensive(root->left) && isBinaryExpensive(root->right) && isLesser(root->left, root->value) && isGreater(root->right, root->value))
        return true;
    return false;
}

bool isBinary(Node *root, int minVal, int maxVal)
{
    // Better Solution
    if (root == NULL)
        return true;
    if (root->value > minVal &&
        root->value < maxVal &&
        isBinary(root->left, minVal, root->value) &&
        isBinary(root->right, root->value, maxVal))
        return true;
    else
        return false;
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
    std::cout << findMax(ROOT) << std::endl;
    std::cout << findMin(ROOT) << std::endl;

    // Getting Height
    std::cout << getHeight(ROOT) << std::endl;

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
    return 0;
}
