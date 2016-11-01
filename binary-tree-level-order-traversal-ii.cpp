// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> rs;
        if (root == NULL) {
            return rs;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count_a_level = q.size();
            rs.push_back(vector<int>());
            for (size_t i = 0; i < count_a_level; ++i) {
                TreeNode* front = q.front();
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
                rs.back().push_back(front->val);
                q.pop();
            }
        }
        reverse(rs.begin(), rs.end());
        return rs;
    }
};
