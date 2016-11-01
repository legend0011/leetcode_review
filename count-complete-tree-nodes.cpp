// https://leetcode.com/problems/count-complete-tree-nodes/

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
        int h = getHeight(root);  // first level, h=0
        if (h == -1) {
            return 0;
        }
        if (h == 0) {
            return 1;
        }
        int left = 0;
        int right = (1 << h) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canGetThere(mid, h, root)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return GetOriginValue(right, h);
    }

private:
    int getHeight(TreeNode* root) {
        int h = -1;
        while (root) {
            ++h;
            root = root->left;
        }
        return h;
    }
    bool canGetThere(int value, int height, TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        TreeNode* node = root;
        for (int i = height; i > 0; --i) {  // height=2 => 00, 01, 10, 11
            int ith_elem = (value >> (i-1)) & 1;
            if (ith_elem == 0) {
               node = node->left;
            } else {
               node = node->right;
            }
            if (node == NULL) {
                return false;
            }
        }
        return true;
    }
    int GetOriginValue(int code, int height) {
        return (1 << height) + code;
    }
};
