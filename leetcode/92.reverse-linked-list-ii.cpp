/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, const int right) {
        if (!head->next || left == right) {
            return head;
        }
        ListNode *current = head, *temp;

        for (int i = 2; i < left; i++) {
            current = current->next;
        }
        if (left == 1) {
            temp = head;
        } else {
            temp = current->next;
        }
        ListNode *end = temp, *prev = end->next, *now = prev->next;

        for (int i = 0; i < right - left && prev; i++) {
            prev->next = end;
            end = prev;
            prev = now;

            if (now) {
                now = now->next;
            }
        }
        if (left == 1) {
            head->next = prev;
            head = end;
        } else {
            current->next = end;
            temp->next = prev;
        }
        return head;
    }
};
// @lc code=end
