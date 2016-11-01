// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        flatHelp(root);
    }
private:
    TreeNode* flatHelp(TreeNode* node) {
        if (node == NULL) {
            return NULL;
        }
        if (node->left == NULL) {
            if (node->right == NULL) {
                return node;
            }
            return flatHelp(node->right);
        }
        TreeNode* right = node->right;
        TreeNode* far_right = flatHelp(node->left);
        node->right = node->left;
        far_right->right = right;
        node->left = NULL;
        if (right) {
            return flatHelp(right);
        } else {
            return far_right;
        }
    }
};
