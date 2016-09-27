//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
	map<int, int> in_map_;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
		for (int i = 0; i < n; ++i) {
			in_map_[inorder[i]] = i;
		}
		return dfs(inorder, 0, n-1, postorder, 0, n-1);
    }
	TreeNode* dfs(vector<int>& inorder, int ileft, int iright,
				  vector<int>& postorder, int pleft, int pright) {
		if (ileft > iright) return NULL;
		int root_val = postorder[pright];
		TreeNode* root = new TreeNode(root_val);
		if (ileft == iright) return root;
		int iroot = in_map_[root_val];
		int len = iroot - 1 - ileft;
		root->left = dfs(inorder, ileft, iroot-1, postorder, pleft, pleft + len);
		root->right = dfs(inorder, iroot+1, iright, postorder, pleft+len+1, pright-1);
		return root;
	}
};
