//https://leetcode.com/problems/count-complete-tree-nodes/
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
    int countNodes(TreeNode* root) {
		if (!root) return 0;
		int level = 0;
		bool flag = checkBalance(root, level);
		if (flag) return countCompleteNodes(level);
		else {
			return countNodes(root->left) + countNodes(root->right) + 1;
		}
    }

	int countCompleteNodes(int level) {
		if (level == 1) return 1;
		int now = 1;
		int sum = 0;
		for (int i = 1; i <= level; ++i) {
			sum += now;
			now *= 2;
		}
		return sum;
	}

    bool checkBalance(TreeNode* root, int& level) {
		TreeNode* node = root;
		int left_level = 0, right_level = 0;
		while (node) {
			++left_level;
			node = node->left;
		}
		node = root;
		while (node) {
			++right_level;
			node = node->right;
		}
		level = min(left_level, right_level);
		return (left_level == right_level);

	}
};
