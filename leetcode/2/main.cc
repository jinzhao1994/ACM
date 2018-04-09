/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int p = l1->val + l2->val;
        ListNode *ans = new ListNode(p % 10), *l3 = ans;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr || l2 != nullptr) {
            p = p / 10;
            if (l1 != nullptr) {
                p += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                p += l2->val;
                l2 = l2->next;
            }
            l3->next = new ListNode(p % 10);
            l3 = l3->next;
        }
        if (p / 10 > 0) {
            l3->next = new ListNode(p / 10);
        }
        return ans;
    }
};
