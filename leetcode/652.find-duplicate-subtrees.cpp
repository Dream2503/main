/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::unordered_map<std::string, int> hash;
        std::vector<TreeNode*> res;
        std::function<std::string(TreeNode*)> serialize = [&](TreeNode *node) -> std::string {
            if (!node) {
                return "#";
            }
            std::string str = std::to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right);

            if (++hash[str] == 2) {
                res.push_back(node);
            }
            return str;
        };
        serialize(root);
        return res;
    }
};
// @lc code=end

