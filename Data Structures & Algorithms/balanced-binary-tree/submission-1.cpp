/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    //int height;
    int treeHeight(TreeNode* node){
        if (node == nullptr)
            return 0;
        int left = treeHeight(node->left);
        int right = treeHeight(node->right);

        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int l = treeHeight(root->left);
        int r = treeHeight(root->right);
        if (abs(l - r) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
