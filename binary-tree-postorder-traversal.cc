//https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		stack<TreeNode*> s;
		TreeNode* node = root;
		s.push(root);
		s.push(root);
		while (!s.empty()) {
			node = s.top();
			s.pop();
			if (!s.empty() && node == s.top()) {
				if (node->right) {
					s.push(node->right);
					s.push(node->right);
				}
				if (node->left) {
					s.push(node->left);
					s.push(node->left);
				}
			} else {
				result.push_back(node->val);
			}
		}
		return result;
    }
};
