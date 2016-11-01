// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        queue<pair<TreeNode*, int>> q;
        if (root) {
            q.push(make_pair(root, 0));
        }
        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front();
            
            // insert into result
            int level_now = front.second;
            if (result.size() <= level_now) {
                vector<int> tmp;
                result.push_back(tmp);
            }
            result[level_now].push_back(front.first->val);
            
            q.pop();
            if (front.first->left) {
                q.push(make_pair(front.first->left, level_now + 1));
            }
            if (front.first->right) {
                q.push(make_pair(front.first->right, level_now + 1));
            }
        }
        return result;
    }
};
