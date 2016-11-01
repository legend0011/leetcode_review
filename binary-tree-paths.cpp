// https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> rs;
        if (root == NULL) {
            return rs;
        }
        PathHelp(root, root, "", &rs);
        return rs;
    }
    void PathHelp(TreeNode* root, TreeNode* node, string path, vector<string>* rs) {
        string path_now;
        if (root == node) {
            path_now = to_string(node->val);
        } else {
            path_now = path + "->" + to_string(node->val);
        }
        if (node->left == NULL && node->right == NULL) {
            rs->push_back(path_now);
            return;
        }
        if (node->left) {
            PathHelp(root, node->left, path_now, rs);
        } 
        if (node->right) {
            PathHelp(root, node->right, path_now, rs);
        }
    }
};
