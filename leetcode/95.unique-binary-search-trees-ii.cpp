/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    std::vector<TreeNode*> generateTrees(const int n) {
        std::function<std::vector<TreeNode*>(int, int)> generate = [&](const int start,
                                                                       const int end) -> std::vector<TreeNode*> {
            static auto comb = [](const int n, int r) -> int {
                if (r > n - r) {
                    r = n - r;
                }
                long res = 1;

                for (int i = 0; i < r; i++) {
                    res *= n - i;
                    res /= i + 1;
                }
                return res;
            };
            std::vector<TreeNode*> res;
            res.reserve(static_cast<int>(comb(2 * n, n)) / (n + 1.0));

            if (start > end) {
                res.push_back(nullptr);
                return res;
            }

            for (int i = start; i <= end; i++) {
                std::vector<TreeNode*> leftTrees = generate(start, i - 1), rightTrees = generate(i + 1, end);

                for (TreeNode* left : leftTrees) {
                    for (TreeNode* right : rightTrees) {
                        auto node = new TreeNode(i);
                        node->left = left;
                        node->right = right;
                        res.push_back(node);
                    }
                }
            }
            return res;
        };
        return generate(1, n);
    }
};
// @lc code=end
