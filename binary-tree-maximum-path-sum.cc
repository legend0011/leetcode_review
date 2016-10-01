//https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res = root->val;
        depth(root, res);
        return res;
}
private:
    int depth(TreeNode* root, int& res)
  {
       if(!root) return 0;
       int a = depth(root->left, res), b = depth(root->right, res);
       res = max(res, a+b+root->val);
       return max(0, max(a, b)+root->val);
  }
};
