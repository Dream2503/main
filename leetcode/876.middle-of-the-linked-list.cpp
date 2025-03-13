/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        ListNode *middle = head, *current = head;

        while (current->next) {
            middle = middle->next;
            current = current->next;

            if (current) {
                current = current->next;
            }
            if (!current) {
                break;
            }
        }
        return middle;
    }
};
// @lc code=end

