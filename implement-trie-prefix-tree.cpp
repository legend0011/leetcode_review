// https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode {
public:
    // Initialize your data structure here.
    // 初始化列表更快，更优先
    TrieNode() : children(26, NULL), val(0), is_word(false) {}
    vector<TrieNode*> children;
    char val;
    bool is_word;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        queue<TrieNode*> q;
        if (root != NULL) {
            q.push(root);
        }
        while (!q.empty()) {
            TrieNode* front = q.front();
            q.pop();
            for (size_t i = 0; i < (front->children).size(); ++i) {
                TrieNode* item = (front->children)[i];
                if (item != NULL) {
                    q.push(item);
                }
            }
            delete front;
        }
    }
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for (size_t i = 0; i < word.size(); ++i) {
            char now = word[i];
            TrieNode* tmp = (p->children)[now - 'a'];
            if (tmp == NULL) {
                // insert a node
                tmp = new TrieNode();
                tmp->val = now;
                (p->children)[now - 'a'] = tmp;
            }
            p = tmp;
            if (i == word.size() - 1) {
                p->is_word = true;
            }
        }
            
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for (size_t i = 0; i < word.size(); ++i) {
            char now = word[i];
            p = (p->children)[now - 'a'];
            if (p == NULL) {
                return false;
            }
        }
        return p->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (size_t i = 0; i < prefix.size(); ++i) {
            char now = prefix[i];
            p = (p->children)[now - 'a'];
            if (p == NULL) {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
