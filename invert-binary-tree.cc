//https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
    	if (!root) return root;
		TreeNode* tmp_right = root->right;
		if (root->left)
			root->right = invertTree(root->left);
		else root->right = NULL;
		if (tmp_right) 
			root->left = invertTree(tmp_right);
		else root->left = NULL;
		return root;
    }
};
