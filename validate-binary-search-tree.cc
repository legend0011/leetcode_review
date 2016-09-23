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
    bool isValidBST(TreeNode* root) {
  		stack<TreeNode*> s;
		TreeNode* node = root;
		TreeNode* last_visit = NULL;
		while (!s.empty() || node) {
			while (node) {
				s.push(node);
				node = node->left;
			}
			node = s.top();
			s.pop();
			if (last_visit && last_visit->val >= node->val) {
				return false;
			}
			last_visit = node;
			node = node->right;
		}     
		return true;
    }
};
