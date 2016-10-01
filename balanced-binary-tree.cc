//https://leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode* root) {
		int depth;
		return isBalanced(root, depth);
    }
	bool isBalanced(TreeNode* root, int& depth) {
		if (!root) {
			depth = 0;
			return true;
		}
		int left_depth, right_depth;
		if (!isBalanced(root->left, left_depth) || !isBalanced(root->right, right_depth)) {
			return false;
		}
		depth = max(left_depth, right_depth) + 1;
		return abs(left_depth - right_depth) <= 1;

	}
};
