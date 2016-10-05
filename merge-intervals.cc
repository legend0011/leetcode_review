#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/merge-intervals/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    static int intervalComp(const Interval& i1, const Interval& i2) {
        return (i2.start - i1.start) > 0;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty()) return result;
        sort(intervals.begin(), intervals.end(), intervalComp);
        int left = 0, right = 0, max_end = intervals[left].end;
        while (right < intervals.size() - 1) {
            ++right;
            if (intervals[right].start <= max_end) {
                max_end = max(max_end, intervals[right].end);
            } else {
                Interval interval(intervals[left].start, max_end);
                result.push_back(interval);
                left = right;
                max_end = intervals[left].end;
            }
        }
        Interval interval(intervals[left].start, max_end);
        result.push_back(interval);
        return result;
    }
};

int main() {
	Solution s;
	vector<Interval> v;
	Interval i1(1,3);
	Interval i2(2,6);
	Interval i3(8,10);
	Interval i4(15,18);
	v.push_back(i1);
	v.push_back(i2);
	v.push_back(i3);
	v.push_back(i4);
	v = s.merge(v);
	cout <<v.size() <<endl;
}
