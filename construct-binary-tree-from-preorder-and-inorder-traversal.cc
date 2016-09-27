//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            in_map_[inorder[i]] = i;
        }
        return dfs(inorder , 0, n-1, preorder, 0, n-1);
    }

    TreeNode* dfs(vector<int>& inorder, int ileft, int iright, vector<int>& preorder, int pleft, int pright) {
        if (pright < pleft) return NULL;
        int root_val = preorder[pleft];
        TreeNode* root = new TreeNode(root_val);
        if (pright == pleft) return root;

        int iroot = in_map_[root_val];
        int len = iroot - ileft;
        root->left = dfs(inorder, ileft, iroot - 1, preorder, pleft + 1, pleft + len);
        root->right = dfs(inorder, iroot + 1, iright, preorder, pleft + len + 1, pright);
        return root;
    }
};
