/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int count(TreeNode* node) {
        if (!node->left && !node->right) {
            return node->val;
        }
        if (!node->right) {
            return node->left->val;
        }
        int res = count(node->right);

        if (!res) {
            return count(node->left);
        }
        return res;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->right && !root->left) {
            return 1;
        }
        return count(root);
    }
};
// @lc code=end
