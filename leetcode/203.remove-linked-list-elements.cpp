/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, const int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        ListNode *prev = nullptr, *current = head;

        while (current) {
            if (current->val == val) {
                prev->next = current->next;
            } else {
                prev = current;
            }
            current = current->next;
        }
        return head;
    }
};
// @lc code=end
