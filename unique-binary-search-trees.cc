class Solution {
public:
	map<int, int> cache_;
    int numTrees(int n) {
		if (n <= 1) return 1;
		if (cache_.find(n) != cache_.end())
			return cache_[n];
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			sum += get_tree_num(i, n);
		}
		cache_[n] = sum;
		return sum;
    }
	int get_tree_num(int root, int n) {
		int left = numTrees(root - 1);
		int right = numTrees(n - root);
		return left * right;
	}
};
