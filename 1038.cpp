/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    void postTraversal(TreeNode *root) {
        if (root == NULL)
            return;

        if (root->right != NULL)
            postTraversal(root->right);
        root->val += sum;
        sum = root->val;
        if (root->left != NULL)
            postTraversal(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        postTraversal(root);
        return root;
    }
};
