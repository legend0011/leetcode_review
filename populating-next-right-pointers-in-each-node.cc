//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
		if (!root) return;
		connectTwoNodes(root->left, root->right);
    }
	void connectTwoNodes(TreeLinkNode* left, TreeLinkNode* right) {
		if (!left) return;
		left->next = right;
		if (!left->left) return;
		connectTwoNodes(left->left, left->right);
		connectTwoNodes(left->right, right->left);
		connectTwoNodes(right->left,right->right);
	}
};
