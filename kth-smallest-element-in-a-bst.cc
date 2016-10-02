//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        inorder(root, &result);
        return result[k-1];
    }
    void inorder(TreeNode* root, vector<int>* result) {
        if (!root) return;
        inorder(root->left, result);
        result->push_back(root->val);
        inorder(root->right, result);
    }
};
