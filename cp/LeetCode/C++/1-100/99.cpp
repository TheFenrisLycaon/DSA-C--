class Solution {
public:
    void recoverTreeHelper(TreeNode *root) {
        
        if (root == NULL) return;
        
        recoverTreeHelper(root->left);
        if (prev) {
            if (prev->val > root->val){
                if (n1==NULL) {
                    n1 = prev;
                }
                n2 = root;
            }
        }
        prev = root;
        recoverTreeHelper(root->right);
    }
    
    void recoverTree(TreeNode *root) {
        n1 = n2 = prev = NULL;
        recoverTreeHelper(root);
        if (n1 && n2) {
            swap(n1->val, n2->val);
        }
    }
private:
    TreeNode *n1, *n2, *prev;
};