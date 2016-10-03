//https://leetcode.com/problems/house-robber-iii/
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
    int rob(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return max(take_map_[root], discard_map_[root]);
    }
private:
    void dfs (TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        dfs(root->right);
        take_map_[root] = root->val + discard_map_[root->left] + discard_map_[root->right];
        discard_map_[root] = max(take_map_[root->left], discard_map_[root->left])
                          + max(take_map_[root->right], discard_map_[root->right]);
    }
    map<TreeNode*, int> take_map_;
    map<TreeNode*, int> discard_map_;
};
