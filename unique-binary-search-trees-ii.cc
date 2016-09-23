#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
		return generateTreesWithRange(1, n);	
	}

    vector<TreeNode*> generateTreesWithRange(int begin, int end) {
		vector<TreeNode*> result;
		if (begin > end) return result;
		for (int i = begin; i <= end; ++i) {
			TreeNode node(i);
			vector<TreeNode*> root_vec;
			gen(&node, begin, end, &root_vec);
			for (int j = 0; j < root_vec.size(); ++j) {
				result.push_back(root_vec[j]);
			}
		}  	      
		return result;
    }
	
	void gen(TreeNode* root, int begin, int end, vector<TreeNode*>* root_vec_ptr) {
		vector<TreeNode*>& root_vec = *root_vec_ptr;
		vector<TreeNode*> left_vec = generateTreesWithRange(begin, root->val - 1);			
		vector<TreeNode*> right_vec = generateTreesWithRange(root->val + 1, end);
		if (left_vec.empty()) left_vec.push_back(NULL);
		if (right_vec.empty()) right_vec.push_back(NULL);
		for (int i = 0; i < left_vec.size(); ++i) {
			for (int j = 0; j < right_vec.size(); ++j) {
				TreeNode* node = new TreeNode(root->val);
				node->left = left_vec[i];
				node->right = right_vec[j];
				root_vec.push_back(node);
			}
		}
	}
};

