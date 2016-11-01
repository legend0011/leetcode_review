// https://leetcode.com/problems/binary-search-tree-iterator/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> st;
    TreeNode *node;
public:
    BSTIterator(TreeNode *root) {
        node = root;
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty() && node == NULL) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        int rs = node->val;
        st.pop();
        node = node->right;
        return rs;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
