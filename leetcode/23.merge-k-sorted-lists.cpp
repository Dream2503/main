/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
        auto comparator = [](const ListNode* a, const ListNode* b) -> bool { return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comparator)> min_heap(comparator);

        for (ListNode* list : lists) {
            if (list) {
                min_heap.push(list);
            }
        }
        ListNode res = ListNode(), *current = &res;

        while (!min_heap.empty()) {
            current->next = min_heap.top();
            current = current->next;
            min_heap.pop();

            if (current->next) {
                min_heap.push(current->next);
            }
        }
        return res.next;
    }
};
// @lc code=end
