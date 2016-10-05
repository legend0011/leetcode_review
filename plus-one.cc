//https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int tmp;
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (c == 0) return digits;
           digits[i] = digits[i] + c;
           if (digits[i] == 10) {
               digits[i] = 0;
               c = 1;
           } else {
               c = 0;
           }
        }
        if (c == 1) {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
