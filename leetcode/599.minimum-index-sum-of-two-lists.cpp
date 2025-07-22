/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> findRestaurant(const std::vector<std::string>& list1,
                                            const std::vector<std::string>& list2) {
        using type = std::pair<int, const std::string*>;
        auto comparator = [](const type& a, const type& b) { return a.first > b.first; };
        const int size1 = list1.size(), size2 = list2.size();
        std::priority_queue<type, std::vector<type>, decltype(comparator)> heap(comparator);

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (list1[i] == list2[j]) {
                    heap.emplace(i + j, &list1[i]);
                    break;
                }
            }
        }
        const int min = heap.top().first;
        std::vector res{*heap.top().second};
        heap.pop();

        while (!heap.empty() && heap.top().first == min) {
            res.push_back(*heap.top().second);
            heap.pop();
        }
        return res;
    }
};
// @lc code=end
