/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(const TreeNode* root) {
        std::deque<std::pair<const TreeNode*, int>> queue;

        if (root) {
            queue.push_back({root, 1});
        }
        while (!queue.empty()) {
            auto [node, depth] = queue.front();
            queue.pop_front();

            if (node->left) {
                queue.push_back({node->left, depth + 1});
            }
            if (node->right) {
                queue.push_back({node->right, depth + 1});
            }
            if (!node->left && !node->right) {
                return depth;
            }
        }
        return 0;
    }
};
// @lc code=end
