/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        const auto split = [](ListNode* node, int n) -> ListNode* {
            while (--n && node) {
                node = node->next;
            }
            if (!node) {
                return nullptr;
            }
            ListNode* res = node->next;
            node->next = nullptr;
            return res;
        };
        const auto merge = [](ListNode* list1, ListNode* list2, ListNode* prev) -> ListNode* {
            ListNode* current = prev;

            while (list1 && list2) {
                if (list1->val < list2->val) {
                    current->next = list1;
                    list1 = list1->next;
                } else {
                    current->next = list2;
                    list2 = list2->next;
                }
                current = current->next;
            }
            current->next = list1 ? list1 : list2;

            while (current->next) {
                current = current->next;
            }
            return current;
        };
        if (!head || !head->next) {
            return head;
        }
        int len = 0;
        const ListNode* node = head;

        while (node) {
            len++;
            node = node->next;
        }
        ListNode dummy(0);
        dummy.next = head;

        for (int i = 1; i < len; i *= 2) {
            ListNode* prev = &dummy;
            ListNode* current = dummy.next;

            while (current) {
                ListNode *left = current, *right = split(left, i);
                current = split(right, i);
                prev = merge(left, right, prev);
            }
        }
        return dummy.next;
    }
};
// @lc code=end
