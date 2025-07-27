#include <algorithm> // Standard algorithms (e.g., sort, find)
#include <array> // std::array container
#include <chrono>
#include <cmath> // Common mathematical functions
#include <deque> // std::deque container
#include <iomanip> // Manipulators for input and output formatting
#include <iostream> // Standard input and output streams
#include <list> // std::list container
#include <map> // std::map and std::multimap containers
#include <numeric> // Numeric operations (e.g., std::accumulate)
#include <numeric>
#include <queue>
#include <random> // Random number generation facilities
#include <set> // std::set and std::multiset containers
#include <stack>
#include <string> // std::string class and related functions
#include <tuple> // std::tuple and related functions
#include <unordered_map> // std::unordered_map and std::unordered_multimap containers
#include <unordered_set> // std::unordered_set and std::unordered_multiset containers
#include <utility> // std::pair and std::make_pair
#include <vector> // std::vector container

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
    std::vector<int> relativeSortArray(std::vector<int> arr1, const std::vector<int> arr2) {
        std::unordered_map<int, int> hash;
        int i = 0;
        hash.reserve(arr2.size());

        for (const int element : arr2) {
            hash.emplace(element, i++);
        }
        std::sort(arr1.begin(), arr1.end(), [&hash](const int a, const int b) {
            const auto itr_a = hash.find(a), itr_b = hash.find(b);

            if (itr_a == hash.end()) {
                return false;
            }
            if (itr_b == hash.end()) {
                return true;
            }
            return hash[a] < hash[b];
        });
        const int last = arr2.back();
        i = arr1.size() - 1;

        while (i >= 0 && arr1[i] != last) {
            i--;
        }
        if (i < arr1.size() - 1) {
            std::sort(arr1.begin() + i + 1, arr1.end());
        }
        return arr1;
    }
};

int main() {
    Solution sol;
    auto start = std::chrono::high_resolution_clock::now();

sol.relativeSortArray({28,6,22,8,44,17}, {22,28,8,6});


    std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Total time taken: " << time.count();

    return 0;
}
