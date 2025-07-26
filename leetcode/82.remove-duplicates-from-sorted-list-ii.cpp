/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* current = head;

        while (head && head->next && head->val == head->next->val) {
            while (current && current->val == head->val) {
                current = current->next;
            }
            head = current;
        }
        if (!head) {
            return head;
        }
        ListNode* prev = head;
        current = head->next;

        while (current) {
            if (current->next && current->val == current->next->val) {
                const int val = current->val;

                while (current && current->val == val) {
                    current = current->next;
                }
                prev->next = current;
            } else {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};
// @lc code=end
