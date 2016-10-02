#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//https://leetcode.com/problems/binary-search-tree-iterator/
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
public:
    BSTIterator(TreeNode *root) {
  		if (root) {
			while(root) {
				cout << "push " << root->val << endl;
				inorder_stack_.push(root);
				root = root->left;
			}
		}      
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       	return !inorder_stack_.empty(); 
    }

    /** @return the next smallest number */
    int next() {
       	TreeNode* node = inorder_stack_.top();
		inorder_stack_.pop();
		int result = node->val;
		if (node->right) {
			node = node->right;
			while (node) {
				inorder_stack_.push(node);
				node = node->left;
			}
		}
		return result;
    }
private:
	stack<TreeNode*> inorder_stack_;
};
int main() {
	TreeNode* root = new TreeNode(1);
  	BSTIterator i = BSTIterator(root);
  	while (i.hasNext()) cout << i.next();
}
