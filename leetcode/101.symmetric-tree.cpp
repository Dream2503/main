/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(const TreeNode* root) {
        std::function<bool(const TreeNode*, const TreeNode*)> is_same = [&](const TreeNode* node1,
                                                                            const TreeNode* node2) -> bool {
            if (!node1 && !node2) {
                return true;
            }
            if (!node1 || !node2) {
                return false;
            }
            if (node1->val != node2->val) {
                return false;
            }
            return is_same(node1->left, node2->right) && is_same(node1->right, node2->left);
        };
        return is_same(root->left, root->right);
    }
};
// @lc code=end

