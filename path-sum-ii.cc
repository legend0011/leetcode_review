//https://leetcode.com/problems/path-sum-ii/
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> result;
		if (!root) return result;
		vector<int> seq;
		findSum(root, sum, seq, &result);
		return result;    
    }

	void findSum(TreeNode* root, int sum, vector<int> seq, vector<vector<int>>* result) {
		if (!root) return;
		seq.push_back(root->val);
		if (sum == root->val && !root->left && !root->right) {
			result->push_back(seq);
			return;
		}
		if (root->left) findSum(root->left, sum - root->val, seq, result);
		if (root->right) findSum(root->right, sum - root->val, seq, result);
		return;
	}
};
