/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *prev = head->next, *current = prev->next;
        head->next = nullptr;

        while (prev) {
            if (prev->val < head->val) {
                prev->next = head;
                head = prev;
            } else {
                ListNode *current_sorted = head->next, *prev_sorted = head;

                while (current_sorted && current_sorted->val < prev->val) {
                    prev_sorted = current_sorted;
                    current_sorted = current_sorted->next;
                }
                if (current_sorted != prev_sorted) {
                    prev_sorted->next = prev;
                    prev->next = current_sorted;
                }
            }
            prev = current;

            if (current) {
                current = current->next;
            }
        }
        return head;
    }
};
// @lc code=end
