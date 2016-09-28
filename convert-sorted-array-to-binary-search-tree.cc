//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		return ConstructBST(nums, 0, nums.size() - 1);
    }
	TreeNode* ConstructBST(vector<int>& nums,
						   int left,
						   int right) {
		if (left > right) return NULL;
		int med = (left + right) / 2;
		TreeNode* root = new TreeNode(nums[med]);
		root->left = ConstructBST(nums, left, med-1);
		root->right = ConstructBST(nums, med+1, right);
		return root;
	}
};
