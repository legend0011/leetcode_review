//https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		int result = 1;
		queue<string> q;
		q.push(beginWord);
		q.push("");
		while (!q.empty()) {
			string str = q.front();
			q.pop();
			if (str.empty() && !q.empty()) {
				result++;
				q.push("");
			} else if (str.empty() && q.empty()) {
				return 0;
			} else {
				for (int i = 0; i < str.size(); ++i) {
					string tmp = str;
					char origin = tmp[i];
					for (char c = 'a'; c <= 'z'; ++c) {
						if (c == origin) continue;
						tmp[i] = c;
						if (tmp == endWord) return result + 1;
						if (wordList.find(tmp) != wordList.end()) {
							wordList.erase(tmp);
							q.push(tmp);
						}
					}
				}
			}
		}
		return result;   
    }
};
