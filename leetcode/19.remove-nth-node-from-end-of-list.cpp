/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, const int n) {
        const ListNode* later = head;
        ListNode* current = head;
        int i;

        for (i = 0; i <= n && later; i++) {
            later = later->next;
        }
        if (i != n + 1) {
            return head->next;
        }
        while (later) {
            later = later->next;
            current = current->next;
        }
        current->next = current->next->next;
        return head;
    }
};
// @lc code=end
