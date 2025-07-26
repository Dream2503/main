/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    void reverse(ListNode* end, ListNode* prev, ListNode* current, const ListNode* stop) {
        while (current != stop) {
            prev->next = end;
            end = prev;
            prev = current;
            current = current->next;
        }
        prev->next = end;
    }

    ListNode* reverseKGroup(ListNode* head, const int k) {
        ListNode *prev = head, *end = head, *last = head;
        bool first = true;

        if (k == 1) {
            return head;
        }

        while (end) {
            for (int i = 1; i < k; i++) {
                if (end->next) {
                    end = end->next;
                } else {
                    return head;
                }
            }
            if (first) {
                head = end;
                first = false;
            } else {
                last->next = end;
                last = prev;
            }
            end = end->next;
            reverse(end, prev, prev->next, end);
            prev = end;
        }
        return head;
    }
};
// @lc code=end
