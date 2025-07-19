/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    std::vector<int> preorderTraversal(const TreeNode* root) {
        std::vector<int> res;
        std::function<void(const TreeNode*)> pre_order = [&](const TreeNode* node) -> void {
            if (node) {
                res.push_back(node->val);
                pre_order(node->left);
                pre_order(node->right);
            }
        };
        pre_order(root);
        return res;
    }
};
// @lc code=end
