/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(const int val = 0, Node* next = nullptr) : val(val), next(next) {}
    };
    Node *head = nullptr, *tail = nullptr;

public:
    MyLinkedList() {}

    int get(const int index) const noexcept {
        const Node* current = head;

        for (int i = 0; i < index && current; i++) {
            current = current->next;
        }
        return current ? current->val : -1;
    }

    void addAtHead(const int val) {
        head = new Node(val, head);

        if (!tail) {
            tail = head;
        }
    }

    void addAtTail(const int val) noexcept {
        if (tail) {
            tail->next = new Node(val);
            tail = tail->next;
        } else {
            head = tail = new Node(val);
        }
    }

    void addAtIndex(const int index, const int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* current = head;

        for (int i = 1; i < index && current; i++) {
            current = current->next;
        }
        if (!current) {
            return;
        }
        if (!current->next) {
            tail->next = new Node(val);
            tail = tail->next;
        } else {
            current->next = new Node(val, current->next);
        }
    }

    void deleteAtIndex(const int index) noexcept {
        if (!head) {
            return;
        }
        Node* prev = head;

        if (!index) {
            if (head == tail) {
                tail = nullptr;
            }
            prev = head;
            head = head->next;
            delete prev;
            return;
        }
        Node* current = head->next;
        prev = head;

        for (int i = 1; i < index && current; i++) {
            prev = current;
            current = current->next;
        }
        if (!current) {
            return;
        }
        if (!current->next) {
            tail = prev;
            delete tail->next;
            tail->next = nullptr;
        } else {
            prev->next = current->next;
            delete current;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
