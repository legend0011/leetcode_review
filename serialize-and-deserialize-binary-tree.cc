#include<iostream>
#include<sstream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
		if (!root) return "[]";
		q.push(root);
		TreeNode* node = NULL;
		stringstream ss;
		vector<string> result;
		int real_size = 1;
		while(!q.empty()) {
			if (real_size == 0) break;
			real_size = 0;
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				node = q.front();
				q.pop();
				if (node) {
					stringstream tmp;
					tmp << node->val;
					result.push_back(tmp.str());
					if (node->left) ++real_size;
					q.push(node->left);
					if (node->right) ++real_size;
					q.push(node->right);
				} else {
					result.push_back("null");
					q.push(NULL);
					q.push(NULL);
				}
			}
		}
		string ret = "[";
		int end_idx = result.size() - 1;
		for (; end_idx >= 0; --end_idx) {
			if (result[end_idx] != "null") break;
		}
		for (int i = 0; i < end_idx; ++i) {
			ret += result[i] + ',';
		}
		ret += result[end_idx] + ']';
		return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		if (data.size() <= 2) return NULL;
		TreeNode* root = NULL;
    	size_t last = 1;  
    	size_t index = data.find_first_of(',', last);  
		vector<TreeNode*> ret;
    	while (index != string::npos)  
    	{  
			string tmp = data.substr(last,index-last);
			if (tmp == "null") {
				ret.push_back(NULL);
			}
        	else {
				ret.push_back(new TreeNode(atoi(tmp.c_str())));  
				cout << "push " << tmp << endl;
			}
        	last = index+1;  
        	index = data.find_first_of(',', last);  
    	}  
    	if (index - last > 0)  
    	{  
			string tmp = data.substr(last, index-last);
			if (tmp == "null]") {
				ret.push_back(NULL);
			}
        	else {
				ret.push_back(new TreeNode(atoi(tmp.c_str())));  
				cout << "push " << tmp << endl;
			}
    	} 
		if (ret.empty()) return root;
		root = ret[0];
		int ret_size = ret.size();
		for (int i = 0; i < ret_size; ++i) {
			if (!ret[i]) continue;
			int left_idx = i * 2 + 1;
			int right_idx = i * 2 + 2;
			if (left_idx < ret_size) ret[i]->left = ret[left_idx];
			if (right_idx < ret_size) ret[i]->right = ret[right_idx];
		}
		return root;
	} 
		
};

// Your Codec object will be instantiated and called as such:
int main() {
	Codec codec;
	int i = 0;
 	TreeNode* root = codec.deserialize("[]");
    cout << codec.serialize(root) << endl;;
}
