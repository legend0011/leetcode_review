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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  		queue<TreeNode*> q;
		if (root) q.push(root);
		vector<vector<int> > result;
		int count = 0;
		while(!q.empty()) {
			++count;
			vector<int> level;
			vector<TreeNode*> level_nodes;
			while(!q.empty()) {
			    TreeNode* node = q.front();
			    q.pop();
			    level.push_back(node->val);
				level_nodes.push_back(node);
			}
			for (int i = 0; i < level_nodes.size(); ++i) {
				TreeNode* node = level_nodes[i];
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			if (count % 2 == 1) {
				result.push_back(level);
			} else {
				reverse(level.begin(), level.end());
				result.push_back(level);
			}
		}      
		return result;
    }
};
