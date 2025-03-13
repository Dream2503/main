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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *create(vector<int> vec) {
    ListNode *head = new ListNode(vec[0]), *current = head;
    
    for (int num: vec) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return head->next;
}
void print(ListNode *head) {
    cout << '[';

    while (head->next) {
        cout << head->val << ", ";
        head = head->next;
    }
    cout << head->val << ']';
}

class Solution {
    public:
        bool isAlienSorted(vector<string> words, string order) {
            unordered_map<char, int> look_up;
            int size = words.size(), i, j, word1_size, word2_size;
            string word1, word2;
            look_up.reserve(26);
    
            for (i = 0; i < 26; i++) {
                look_up[order[i]] = i;
            }
            for (i = 0; i < size - 1; i++) {
                word1 = words[i]; word2 = words[i + 1];
                word1_size = word1.size(); word2_size = word2.size();
                j = 0;
    
                while (j < word1_size && j < word2_size && look_up[word1[j]] <= look_up[word2[j]]) {
                    j++;
                }
                if (j == word1_size || j == word2_size) {
                    if (word1 != word2) {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            return true;
        }
    };

int main() {
    Solution sol;
    auto start = chrono::high_resolution_clock::now();
    sol.isAlienSorted({"hello","leetcode"}, "hlabcdefgijkmnopqrstuvwxyz");
    chrono::duration<double> time = chrono::high_resolution_clock::now() - start;
    cout << "Total time taken: " << time.count();
    
    return 0;
}