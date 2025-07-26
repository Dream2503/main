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
#include <stack>
#include <queue>
#include <chrono>
#include "all_in_one.hpp"

struct ListNode {
    int val;
    ListNode* next;

    ListNode():
        val(0), next(nullptr) {
    }

    ListNode(int x):
        val(x), next(nullptr) {
    }

    ListNode(int x, ListNode* next):
        val(x), next(next) {
    }
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() :
        val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) :
        val(x), left(left), right(right) {
    }
};

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//
// ListNode* create(vector<int> vec) {
//     ListNode *head = new ListNode(vec[0]), *current = head;
//
//     for (int num : vec) {
//         current->next = new ListNode(num);
//         current = current->next;
//     }
//     return head->next;
// }
//
// void print(ListNode* head) {
//     cout << '[';
//
//     while (head->next) {
//         cout << head->val << ", ";
//         head = head->next;
//     }
//     cout << head->val << ']';
// }

class Solution {
public:
    int findLucky(std::vector<int> arr) {
        std::sort(arr.begin(), arr.end());
        const size_t len = arr.size();
        int i = 0, res = -1;

        while (i < len) {
            if (i + arr[i] - 1 < len && arr[i] == arr[i + arr[i] - 1] && (i + arr[i] < len && arr[i] != arr[i + arr[i]])
                ||
                i + arr[i] - 1 < len && arr[i] == arr[i + arr[i] - 1] && (i + arr[i] >= len)) {
                res = std::max(arr[i], res);
                i += arr[i] - 1;
            }
            while (i + 1 < len && arr[i] == arr[i + 1]) {
                i++;
            }
            i++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << sol.findLucky({14, 14, 19, 11, 6, 4, 16, 17, 3, 7, 7, 5, 15, 12, 3, 20, 1, 13, 5, 20, 1, 12, 10, 2});
    std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Total time taken: " << time.count();

    return 0;
}
