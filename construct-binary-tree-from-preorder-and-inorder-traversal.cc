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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	TreeNode* root = NULL;
		if (preorder.empty()) return root;
		root = new TreeNode(preorder[0]);
		vector<int> left_preorder;
		vector<int> left_inorder;
		vector<int> right_preorder;
		vector<int> right_inorder;
		findSubInorder(inorder, root->val, &left_inorder, &right_inorder);
		findSubPreorder(preorder, left_inorder.size(), &left_preorder, &right_preorder);
		root->left = buildTree(left_preorder, left_inorder);
		root->right = buildTree(right_preorder, right_inorder);
		return root;
    }
	void findSubPreorder(const vector<int>& preorder_vec,
				  const int& sep_index,
				  vector<int>* left_preorder_vec_ptr,
				  vector<int>* right_preorder_vec_ptr) {
		vector<int>& left_preorder_vec = *left_preorder_vec_ptr;
		vector<int>& right_preorder_vec = *right_preorder_vec_ptr;
		// get preorder
		for (int i = 1; i < preorder_vec.size(); ++i) {
			if (i <= sep_index) {
				left_preorder_vec.push_back(preorder_vec[i]);
			} else {
				right_preorder_vec.push_back(preorder_vec[i]);
			}
		}

	}
	void findSubInorder(const vector<int>& inorder_vec,
				  const int& find_value,
				  vector<int>* left_inorder_vec_ptr,
				  vector<int>* right_inorder_vec_ptr) {
		vector<int>& left_inorder_vec = *left_inorder_vec_ptr;
		vector<int>& right_inorder_vec = *right_inorder_vec_ptr;
		// get inorder
		bool left_flag = true;
		for (int i = 0; i < inorder_vec.size(); ++i) {
			if (inorder_vec[i] == find_value) {
				left_flag = false;
				continue;
			}
			if (left_flag) {
				left_inorder_vec.push_back(inorder_vec[i]);
			} else {
				right_inorder_vec.push_back(inorder_vec[i]);
			}
		}

};
