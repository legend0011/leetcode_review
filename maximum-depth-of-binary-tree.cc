//https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root) {
		if (!root) return 0;
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		int level = 0;
		while (q.size() > 1) {
			++level;
			queue<TreeNode*> tmp_q;
			while (!q.empty()) {
				TreeNode* node = q.front();
				q.pop();
				if (!node) {
					q.push(NULL);
					break;
				}
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		return level;
    }
};
