//https://leetcode.com/problems/insert-interval/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        if (intervals.empty()) {
            result.push_back(newInterval);
            return result;
        }
        bool inserted = false;
        Interval* left = NULL;
        int max_end = 0;
        if (intervals[0].start < newInterval.start) {
            max_end = intervals[0].end;
            left = &intervals[0];
        } else { 
            max_end = newInterval.end;
            left = &newInterval;
        }
        for (int i = 0; i < intervals.size(); ++i) {
            if (newInterval.start <= intervals[i].start) {
                inserted = true;
                if (newInterval.start <= max_end) {
                    max_end = max(max_end, newInterval.end);
                } else {
                    Interval tmp(left->start, max_end);
                    result.push_back(tmp);
                    left = &newInterval;
                    max_end = newInterval.end;
                }
            }
            if (intervals[i].start <= max_end) {
                max_end = max(max_end, intervals[i].end);
            } else {
                Interval tmp(left->start, max_end);
                result.push_back(tmp);
                left = &intervals[i];
                max_end = intervals[i].end;
            }
        }
        if (!inserted) {
            if (newInterval.start <= max_end) {
                max_end = max(max_end, newInterval.end);
            } else {
                Interval tmp(left->start, max_end);
                result.push_back(tmp);
                result.push_back(newInterval);
                return result;
            }
        }
        Interval tmp(left->start, max_end);
        result.push_back(tmp);
        
        return result;
    }
};
