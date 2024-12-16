/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        string direction = "right";
        int row = matrix.size(), column = matrix[0].size(), i = 0, j = 0;
        set<pair<int,int>> seen;
        vector<int> res;
        res.reserve(row * column);
        bool change;

        while (true) {
            if (direction == "right") {
                if (j < column && seen.find({i, j}) == seen.end()) {
                    res.push_back(matrix[i][j]);
                    seen.insert({i, j});
                    change = false;
                    j++;
                } else {
                    if (change) {
                        break;
                    }
                    direction = "down";
                    i++;
                    j--;
                    change = true;
                }
            } else if (direction == "down") {
                if (i < row && seen.find({i, j}) == seen.end()) {
                    res.push_back(matrix[i][j]);
                    seen.insert({i, j});
                    change = false;
                    i++;
                } else {
                    if (change) {
                        break;
                    }
                    direction = "left";
                    j--;
                    i--;
                    change = true;
                }
            } else if (direction == "left") {
                if (j > -1 && seen.find({i, j}) == seen.end()) {
                    res.push_back(matrix[i][j]);
                    seen.insert({i, j});
                    change = false;
                    j--;
                } else {
                    if (change) {
                        break;
                    }
                    direction = "up";
                    i--;
                    j++;
                    change = true;
                }
            } else if (direction == "up") {
                if (i > -1 && seen.find({i, j}) == seen.end()) {
                    res.push_back(matrix[i][j]);
                    seen.insert({i, j});
                    change = false;
                    i--;
                } else {
                    if (change) {
                        break;
                    }
                    direction = "right";
                    j++;
                    i++;
                    change = true;
                }
            }
        }
        return res;
    }
};
// @lc code=end

