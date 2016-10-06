//https://leetcode.com/problems/search-a-2d-matrix/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
    	if (matrix.empty()) return false;
		const int m = matrix.size(), n = matrix[0].size(); 
		int x, y, mid;
		int left = 0, right = xy2index(m - 1, n - 1, n);
		while (left <= right) {
			mid = (left + right) / 2;
			index2xy(mid, n, &x, &y);
			if (matrix[x][y] == target) return true;
			else if (matrix[x][y] < target) left = mid + 1;
			else right = mid - 1;
		}
		return false;
    }
	int xy2index(const int& x, const int& y, const int& n) {
		return x * n + y;
	}
	void index2xy(const int&index, const int& n, int* x, int* y) {
		*y = index % n;
		*x = index / n;
	}
	
};
int main() {
	vector<vector<int> > m;
	vector<int> v(1,1);
	m.push_back(v);
	Solution s;
	cout<<s.searchMatrix(m,0)<<endl;
}
