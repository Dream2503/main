/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string>& removeSubfolders(std::vector<std::string>& folder) {
        std::sort(folder.begin(), folder.end());
        const int size = folder.size();
        int i = 0, j = 1;

        while (j < size) {
            const std::string_view first = folder[i];
            const int k = first.length();

            while (j < size) {
                const std::string_view second = folder[j];

                if (first == second.substr(0, k) && second[k] == '/') {
                    j++;
                } else {
                    if (i != j + 1) {
                        std::swap(folder[++i], folder[j++]);
                    } else {
                        i++;
                        j++;
                    }
                    break;
                }
            }
        }
        folder.resize(i + 1);
        return folder;
    }
};
// @lc code=end
