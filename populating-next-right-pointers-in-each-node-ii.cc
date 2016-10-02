//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
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
		if (root->left && root->right) {
			root->left->next = root->right;
		} 
		TreeNode* start_node = root->right;
		if (!root->right) {
			start_node = root->left;
		}
		if (start_node) {
			TreeNode* parent_node = root->next;
			while (parent_node && !parent_node->left && !parent_node->right) {
				parent_node = parent_node->next;
			}
			if (parent_node) {
				if (parent_node->left) start_node->next = parent_node->left;
				else if (parent_node->right) start_node->next = parent_node->right;
			} 		
		}  
		if (root->right) connect(root->right);
		if (root->left) connect(root->left);
    }
};
