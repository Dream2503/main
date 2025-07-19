/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, const int x) {
        ListNode *left = nullptr, *right = nullptr, *left_current = nullptr, *right_current = nullptr;

        while (head) {
            if (head->val < x) {
                if (left) {
                    left_current->next = head;
                    left_current = left_current->next;
                } else {
                    left_current = left = head;
                }
            } else {
                if (right) {
                    right_current->next = head;
                    right_current = right_current->next;
                } else {
                    right_current = right = head;
                }
            }
            head = head->next;
        }
        if (left_current) {
            left_current->next = right;
        } else {
            return right;
        }
        if (right_current) {
            right_current->next = nullptr;
        }
        return left;
    }
};
// @lc code=end
