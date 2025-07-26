/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if (!head->next) {
            return true;
        }
        ListNode* slow = head;
        const ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            slow = slow->next;
        }
        ListNode* stop = slow;
        ListNode *end = nullptr, *prev = slow, *current = slow->next;

        while (prev) {
            prev->next = end;
            end = prev;
            prev = current;

            if (current) {
                current = current->next;
            }
        }
        while (head != stop && end != nullptr) {
            if (head->val != end->val) {
                return false;
            }
            head = head->next;
            end = end->next;
        }
        return true;
    }
};
// @lc code=end
