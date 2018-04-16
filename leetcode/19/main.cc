/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int sz = 0;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next) sz++;
        n = sz - n;
        if (n == 0) {
            return head->next;
        }
        ListNode *tmp = head;
        for (int i = 1; i < n; i++) {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return head;
    }
};
