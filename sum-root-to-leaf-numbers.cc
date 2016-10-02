//https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    int sumNumbers(TreeNode* root) {
    	vector<int> result;
		int now = 0;
		if (root) traversal(root, now, &result);
		int sum = 0;
		for (int i = 0; i < result.size(); ++i) {
			sum += result[i];
		}    
		return sum;
    }
	void traversal(TreeNode* root, int now, vector<int>* result) {
		now = now * 10 + root->val;
		if (!root->left && !root->right) {
			result->push_back(now);
			return;
		}
		if (root->left) traversal(root->left, now, result);
		if (root->right) traversal(root->right, now, result);
	}
};
