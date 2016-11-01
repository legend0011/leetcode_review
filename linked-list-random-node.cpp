// https://leetcode.com/problems/linked-list-random-node/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        head_ = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        const ListNode* p = head_;
        int count = 1;
        int result = head_->val;
        while (p) {
            if ((rand() + 1) % count == 0) {  // possibility=1/count, rand() returns a pseudo-random integral number in the range between 0 and RAND_MAX.
                result = p->val;
            }
            p = p->next;
            ++count;
        }
        return result;
    }
private:
    const ListNode* head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
