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
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
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
        vector<string> commonChars(vector<string> words) {
            string res = words[0];
            int i, j, size1, size2;
            sort(res.begin(), res.end());
    
            for (string &word: words) {
                sort(word.begin(), word.end());
                if (res == word) {
                    continue;
                }
                i = j = 0;
                size1 = res.size();
                size2 = word.size();
    
                while (i < size1 && j < size2) {
                    while (i < size1 && res[i] < word[j]) {
                        res.erase(res.begin() + i);
                        size1--;
                    }
                    while (j < size2 && res[i] > word[j]) {
                        word.erase(word.begin() + j);
                        size2--;
                    }
                    if (res[i] != res[j]) {
                        
                    }
                    i++; j++;
                }
                if (i < size1) {
                    res.erase(res.begin() + i, res.end());
                }
                if (j < size2) {
                    word.erase(word.begin() + j, word.end());
                }
                res = res.size() > word.size() ? word : res;
            }
            vector<string> rtn;
            rtn.reserve(res.size());
            transform(res.begin(), res.end(), back_inserter(rtn), [](char c){return string(c, 1);});
            return rtn;
        }
    };

int main() {
    Solution sol;
    auto start = chrono::high_resolution_clock::now();
    sol.commonChars({"cool","lock","cook"});
    chrono::duration<double> time = chrono::high_resolution_clock::now() - start;
    cout << "Total time taken: " << time.count();
    
    return 0;
}
