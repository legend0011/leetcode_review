//https://leetcode.com/problems/anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string,vector<string>*> m;
        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            string hash_code = getHashCode(str);
            if (m.find(hash_code) == m.end()) {
                m[hash_code] = new vector<string>();
            }
            m[hash_code]->push_back(str);
        }
        for (auto pair : m) {
            vector<string>& vec = *(pair.second);
            sort(vec.begin(), vec.end());
            result.push_back(vec);
        }
        return result;
    }
    string getHashCode(const string& str) {
        string tmp = str;
        sort(tmp.begin(), tmp.end());
        return tmp;
    }
};
