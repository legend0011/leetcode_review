//https://leetcode.com/problems/sum-of-left-leaves/
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
    int sumOfLeftLeaves(TreeNode* root) {
    	if (!root) return 0;
		if (!root->left && !root->right) return 0;
		int left_sum = 0, right_sum = 0;
		if (root->left) {
			if (!root->left->left && !root->left->right) left_sum = root->left->val;
			else left_sum = sumOfLeftLeaves(root->left);
		}
		if (root->right) {
			right_sum = sumOfLeftLeaves(root->right);
		}
		return left_sum + right_sum;
    }
};
