//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
		vector<int> array;
    	while (head) {
			array.push_back(head->val);
			head = head->next;
		}    
		return ConstructBST(array, 0, array.size()-1);
    }
	TreeNode* ConstructBST(vector<int>& array, int left, int right) {
		if (left > right) return NULL;
		int med = (left + right) / 2;
		TreeNode* root = new TreeNode(array[med]);
		root->left = ConstructBST(array, left, med-1);
		root->right = ConstructBST(array, med+1, right);
		return root;
	}
};
