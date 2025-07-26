/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode *odd = head, *current_odd = odd, *even = head->next, *current_even = even;
        head = head->next->next;

        while (head) {
            current_odd->next = head;
            current_odd = current_odd->next;
            head = head->next;

            if (head) {
                current_even->next = head;
                current_even = current_even->next;
                head = head->next;
            }
        }
        current_even->next = nullptr;
        current_odd->next = even;
        return odd;
    }
};
// @lc code=end
