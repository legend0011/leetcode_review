// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rs;
        queue<TreeNode*> q;
        if (root == NULL) {
            return rs;
        }
        q.push(root);
        while (!q.empty()) {
            int level_node_count = q.size();
            for (int i = 0; i < level_node_count; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (i == level_node_count - 1) {
                    rs.push_back(node->val);
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return rs;
    }
};
