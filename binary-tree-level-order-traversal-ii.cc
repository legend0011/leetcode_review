//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) return result;
  		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		while(q.size() > 1) {
			vector<int> vec;
			while(!q.empty()) {
				TreeNode* node = q.front();
				q.pop();
				if (!node) break;
				vec.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			q.push(NULL);
			result.push_back(vec);
		}      
		reverse(result.begin(), result.end());
		return result;
    }
};
