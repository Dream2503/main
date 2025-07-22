/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        std::function<Node*(Node*)> open = [&](Node* current) -> Node* {
            Node* prev = nullptr;

            while (current) {
                prev = current;

                if (current->child) {
                    Node *temp = current->next, *child = current->child;
                    current->next = child;
                    current->child->prev = current;
                    current->child = nullptr;
                    Node* res = open(child);
                    current = temp;

                    if (current) {
                        res->next = current;
                        current->prev = res;
                    } else {
                        prev = res;
                    }
                } else {
                    current = current->next;
                }
            }
            return prev;
        };
        if (head) {
            open(head);
        }
        return head;
    }
};
// @lc code=end
