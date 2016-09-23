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
    void recoverTree(TreeNode* root) {
		stack<TreeNode*> s;
		TreeNode* node = root;
		TreeNode* last_node = NULL;
		TreeNode* first = NULL;
		TreeNode* second = NULL;
		while (!s.empty() || node) {
			while (node) {
				s.push(node);
				node = node->left;
			}
			node = s.top();
			s.pop();
			if (last_node && last_node->val > node->val) {
				if (!first) first = last_node;
				if (first) second = node;
			}
			last_node = node;
			node = node->right;
		}

		if (first && second) {
			swap(first->val, second->val);
		}
    }
};
