/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
 1->4->5,
 1->3->4,
 2->6
]

Output: 1->1->2->3->4->4->5->6

 */

#include <queue>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Compare {
public:
    bool operator()(const ListNode *a, const ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue < ListNode * , std::vector < ListNode * >, Compare > c;
        for (auto &node : lists) {
            if (node != nullptr) {
                c.push(node);
            }
        }
        ListNode *ans = nullptr, *tail = nullptr;
        while (c.size() != 0) {
            ListNode *tmp = c.top();
            if (tail == nullptr) {
                ans = tail = tmp;
            } else {
                tail->next = tmp;
                tail = tmp;
            }
            c.pop();
            if (tmp->next != nullptr) {
                c.push(tmp->next);
            }
        }
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        return ans;
    }
};
