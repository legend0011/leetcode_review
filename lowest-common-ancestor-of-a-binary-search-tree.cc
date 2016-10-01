//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	TreeNode* result = NULL;
		TreeNode* left = p;
		TreeNode* right = q;
		if (left->val > right->val) swap(left, right);
		while(root) {
			if (root->val < left->val) {
				root = root->right;
			} else if (root->val > right->val) {
				root = root->left;
			} else {
				result = root;
				break;
			}
		}    
		return result;
    }
};
