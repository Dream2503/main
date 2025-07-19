/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        const ListNode* current = head;
        int size = 0;

        while (current) {
            current = current->next;
            size++;
        }
        std::function<TreeNode*(int)> create = [&](const int n) -> TreeNode* {
            if (n <= 0) {
                return nullptr;
            }
            TreeNode* left = create(n / 2);
            const auto root = new TreeNode(head->val);
            head = head->next;
            TreeNode* right = create(n - n / 2 - 1);
            root->left = left;
            root->right = right;
            return root;
        };
        return create(size);
    }
};
// @lc code=end
