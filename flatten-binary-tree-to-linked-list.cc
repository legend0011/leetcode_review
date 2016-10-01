//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
		if (!root) return;
		TreeNode* right_child = root->right;
		TreeNode* left_child = root->left;
  		flatten(right_child);
		if (!left_child) {
			root->right = right_child;
			return;
		}
		TreeNode* left_tail = left_child;
  		flatten(left_child);
		root->left = NULL;
		while (left_tail->right) {
			left_tail = left_tail->right;
		}
		root->right = left_child;
		left_tail->right = right_child;     
    }
};

