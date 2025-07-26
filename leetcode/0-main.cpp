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
    bool canThreePartsEqualSum(std::vector<int> arr) {
        const int size = arr.size();
        int target = std::accumulate(arr.begin(), arr.end(), 0), i = 0, j, sum;

        if (target % 3 != 0) {
            return false;
        }
        target /= 3;

        for (j = 0; j < 3; j++) {
            sum = 0;

            while (i < size && sum != target) {
                sum += arr[i++];
            }
        }
        return j == 3 && sum == target;
    }
};

int main() {
    Solution sol;
    auto start = std::chrono::high_resolution_clock::now();


    std::cout << sol.canThreePartsEqualSum({0,2,1,-6,6,-7,9,1,2,0,1});


    std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Total time taken: " << time.count();

    return 0;
}
