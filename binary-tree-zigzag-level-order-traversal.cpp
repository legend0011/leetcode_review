// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> rs;
        if (root == NULL) {
            return rs;
        }
        queue<TreeNode*> q;
        q.push(root);
        int reverse_signal = -1;
        while (!q.empty()) {
            size_t level_node_count = q.size();
            vector<int> tmp;
            for (size_t i = 0; i < level_node_count; ++i) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (reverse_signal == 1) {
                reverse(tmp.begin(), tmp.end());
            }
            reverse_signal *= (-1);
            rs.push_back(tmp);
        }
        return rs;
    }
};
