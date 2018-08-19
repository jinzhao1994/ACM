/*

Given a linked list, swap every two adjacent nodes and return its head.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:
Your algorithm should use only constant extra space.
You may not modify the values in the list&#39;s nodes, only nodes itself may be changed.

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
    ListNode *swapPairs(ListNode *head) {
        ListNode *ans = nullptr, *tail = nullptr;
        while (head != nullptr && head->next != nullptr) {
            ListNode *a = head, *b = head->next;
            head = b->next;
            if (ans == nullptr) {
                ans = tail = b;
                tail->next = a;
                tail = a;
            } else {
                tail->next = b;
                b->next = a;
                tail = a;
            }
        }
        if (head != nullptr) {
            if (ans == nullptr) {
                ans = tail = head;
            } else {
                tail->next = head;
                tail = head;
            }
        }
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        return ans;
    }
};
