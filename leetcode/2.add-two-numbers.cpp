/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) {
        int carry = 0;
        ListNode *res = new ListNode, *current = res;

        while (l1 || l2) {
            int sum = 0;

            if (l1) {
                sum += l1->val + carry;
                carry = 0;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val + carry;
                carry = 0;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->val = sum % 10;

            if (l1 || l2) {
                current->next = new ListNode;
                current = current->next;
            }
        }
        if (carry) {
            current->next = new ListNode(carry);
        }
        return res;
    }
};
// @lc code=end
