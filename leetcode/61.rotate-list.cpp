/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!k || !head || !head->next) {
            return head;
        }
        ListNode* current = head->next;
        int len = 1;

        while (current) {
            current = current->next;
            len++;
        }
        k %= len;

        if (!k) {
            return head;
        }
        current = head;

        for (int i = 1; i < len - k; i++) {
            current = current->next;
        }
        ListNode* temp = current->next;
        current->next = nullptr;
        current = temp;

        while (current->next) {
            current = current->next;
        }
        current->next = head;
        head = temp;
        return head;
    }
};
// @lc code=end
