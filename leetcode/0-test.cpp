#include <iostream>       // Standard input and output streams
#include <iomanip>        // Manipulators for input and output formatting
#include <string>         // std::string class and related functions
#include <vector>         // std::vector container
#include <array>          // std::array container
#include <list>           // std::list container
#include <deque>          // std::deque container
#include <set>            // std::set and std::multiset containers
#include <map>            // std::map and std::multimap containers
#include <unordered_set>  // std::unordered_set and std::unordered_multiset containers
#include <unordered_map>  // std::unordered_map and std::unordered_multimap containers
#include <algorithm>      // Standard algorithms (e.g., sort, find)
#include <utility>        // std::pair and std::make_pair
#include <tuple>          // std::tuple and related functions
#include <random>         // Random number generation facilities
#include <cmath>          // Common mathematical functions
#include <numeric>        // Numeric operations (e.g., std::accumulate)
#include <queue>
#include <chrono>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// ListNode *create(vector<int> vec) {
//     ListNode *head = new ListNode(vec[0]), *current = head;
    
//     for (int num: vec) {
//         current->next = new ListNode(num);
//         current = current->next;
//     }
//     return head->next;
// }
// void print(ListNode *head) {
//     cout << '[';

//     while (head->next) {
//         cout << head->val << ", ";
//         head = head->next;
//     }
//     cout << head->val << ']';
// }

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> matrix) {
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
                    i++;
                    change = true;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto start = chrono::high_resolution_clock::now();
    sol.spiralOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    chrono::duration<double> time = chrono::high_resolution_clock::now() - start;
    cout << "Total time taken: " << time.count();
    
    return 0;
}