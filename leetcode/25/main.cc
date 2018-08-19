/*

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list.
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:
Only constant extra memory is allowed.
You may not alter the values in the list&#39;s nodes, only nodes itself may be changed.

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
    bool hasK(ListNode *head, int k) {
        for (int i = 0; i < k; i++, head = head->next) {
            if (head == nullptr) {
                return false;
            }
        }
        return true;
    }

    // must check before call this method
    void reverseK(ListNode *oldHead, int k, ListNode *&head, ListNode *&tail, ListNode *&next) {
        ListNode *a = nullptr, *b = oldHead, *c = oldHead->next;
        for (int i = 1; i < k; i++) {
            a = b;
            b = c;
            c = c->next;
            b->next = a;
        }
        head = b;
        tail = oldHead;
        next = c;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *ans = nullptr, *tail = nullptr;
        while (hasK(head, k)) {
            if (ans == nullptr) {
                reverseK(head, k, ans, tail, head);
            } else {
                reverseK(head, k, tail->next, tail, head);
            }
        }
        if (ans == nullptr) {
            ans = head;
        } else {
            tail->next = head;
        }
        return ans;
    }
};
