//https://leetcode.com/problems/word-search/
class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        if (board.empty()) return false;
		if (word.empty()) return true;
		const int m = board.size(), n = board[0].size();
		vector<vector<bool> > visited;
		for (int i = 0; i < m; ++i) {
			vector<bool> v(n, false);
			visited.push_back(v);
		}
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (findWord(board, i, j, m, n, word, 0, word.size(), &visited)) return true;
		return false;
    }
	bool findWord(const vector<vector<char> >& board, const int& i, const int& j,
			  const int& m, const int& n,
			  const string& word, const int& start, const int& size, 
			  vector<vector<bool> >* visited_ptr) {
		vector<vector<bool> >& visited = *visited_ptr;
		if (board[i][j] != word[start]) return false;
		if (start + 1 == size) return true;
		visited[i][j] = true;
		bool find_it = false;
		if (!find_it && i + 1 < m && !visited[i+1][j]) find_it = findWord(board, i+1, j, m, n, word, start+1, size, visited_ptr);
		if (!find_it && i - 1 >= 0 && !visited[i-1][j]) find_it = findWord(board, i-1, j, m, n, word, start+1, size, visited_ptr);
		if (!find_it && j + 1 < n && !visited[i][j+1]) find_it = findWord(board, i, j+1, m, n, word, start+1, size, visited_ptr);
		if (!find_it && j - 1 >= 0 && !visited[i][j-1]) find_it = findWord(board, i, j-1, m, n, word, start+1, size, visited_ptr);
		visited[i][j] = false;
		return find_it;
	}
};

