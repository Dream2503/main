/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 */

// @lc code=start
class Solution {
    const std::vector<std::vector<int>>& rectangles;
    std::vector<int> areas;
    const int size;
    int total_area;

public:
    Solution(const std::vector<std::vector<int>>& rects) :
        rectangles(rects), areas(), size(rects.size()), total_area(0) {
        areas.reserve(size);

        for (const std::vector<int>& vec : rects) {
            total_area += (vec[2] - vec[0] + 1) * (vec[3] - vec[1] + 1);
            areas.push_back(total_area);
        }
    }

    std::vector<int> pick() {
        const int rand_area = std::rand() % total_area;
        const std::vector<int>& temp =
            rectangles[std::lower_bound(areas.begin(), areas.end(), rand_area + 1) - areas.begin()];
        int x = temp[0] + std::rand() % (temp[2] - temp[0] + 1);
        int y = temp[1] + std::rand() % (temp[3] - temp[1] + 1);
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end
