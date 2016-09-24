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
    bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return checkSame(root->left, root->right);
    }
	bool checkSame(TreeNode* left, TreeNode* right) {
		if ((left == NULL) ^ (right == NULL)) return false;
		if (left == NULL && right == NULL) return true;
		if (left->val != right->val) return false;
		return checkSame(left->left, right->right) && checkSame(left->right, right->left);
	}
};
