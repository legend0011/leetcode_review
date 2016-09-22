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
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> s;
		TreeNode* node = root;
		while(!s.empty() || node) {
			while (node) {
				s.push(node);	
				node = node->left;
			}
			if (!s.empty()) {
				node = s.top();
				result.push_back(node->val);
				s.pop();
				node = node->right;
			}
		}
		return result;
    }
};
