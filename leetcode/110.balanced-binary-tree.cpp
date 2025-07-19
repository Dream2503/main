/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
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
    bool isBalanced(const TreeNode* root) {
        std::function<int(const TreeNode*)> check = [&](const TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            const int left = check(node->left);

            if (left == -1) {
                return -1;
            }
            const int right = check(node->right);

            if (right == -1 || std::abs(left - right) > 1) {
                return -1;
            }
            return std::max(left, right) + 1;
        };
        return check(root) != -1;
    }
};
// @lc code=end
