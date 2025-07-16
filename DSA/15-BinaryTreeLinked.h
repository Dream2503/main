#pragma once
#include "12-DequeLinkedList.h"

template <typename type>
class Tree {
    struct Node {
        type data;
        Node *left, *right;
        Node(const type data = type(), Node* left = nullptr, Node* right = nullptr) :
            data(data), left(left), right(right) {}
    };
    Node* root = nullptr;

    Tree(const type* begin, const type* end) {
        DequeLinkedList<Node*> queue;
        root = new Node(*begin);
        const type* itr = begin + 1;

        while (itr != end) {
            Node* current = queue.delete_left();

            if (*itr != type()) {
                current->left = new Node(*itr);
                queue.insert_right(current->left);
                itr++;
            }
            if (itr != end && *itr != type()) {
                current->right = new Node(*itr);
                queue.insert_right(current->right);
                itr++;
            }
        }
    }

    Node* create(Node* node, const char* child, const type& value) {
        type temp;
        std::cout << "Enter the " << child;
        child[1] == 'o' ? std::cout << " value" : std::cout << " of " << value;
        std::cout << " to insert into the tree (-1 to stop): ";
        std::cin >> temp;

        if (temp != -1) {
            node = new Node(temp);
        } else {
            return nullptr;
        }
        node->left = create(node->left, "left child", node->data);
        node->right = create(node->right, "right child", node->data);
        return node;
    }

    Node* create(Node* destination, Node* source) {
        if (source) {
            destination = new Node(source->data);
            destination->left = create(destination->left, source->left);
            destination->right = create(destination->right, source->right);
        }
        return destination;
    }

    void in(Node* node) {
        if (node) {
            in(node->left);
            std::cout << node->data << ' ';
            in(node->right);
        }
    }

    void post(Node* node) {
        if (node) {
            post(node->left);
            post(node->right);
            std::cout << node->data << ' ';
        }
    }

    void pre(Node* node) {
        if (node) {
            std::cout << node->data << ' ';
            pre(node->left);
            pre(node->right);
        }
    }

public:
    Tree() { root = create(root, "root", type()); }

    Tree(const std::initializer_list<type> list) : Tree(list.begin(), list.end()) {}

    Tree(const type* list, const size_t size) : Tree(list, list + size) {}

    Tree(const Tree& tree) { root = create(root, tree.root); }

    Tree(Tree&& other) noexcept : root(other.root) {}

    Tree& operator=(const Tree& other) {
        if (this == &other) {
            return *this;
        }
        root = other.root;
        return *this;
    }

    Tree& operator=(Tree&& other) noexcept {
        if (this == &other)
            return *this;
        root = other.root;
        return *this;
    }

    void insert(const type& after, const char* position = "left", const type& value = type(),
                const char* deep_position = "left") {
        Node *node = find(after), temp;

        if (position[0] == 'l') {
            temp = node->left;
            node->left = new Node(value);
            node = node->left;
        } else if (position[0] == 'r') {
            temp = node->right;
            node->right = new Node(value);
            node = node->right;
        }
        if (deep_position[0] == 'l') {
            node->left = temp;
        } else if (deep_position[0] == 'r') {
            node->right = temp;
        }
    }

    int count() { return 0; }

    void in_order() {
        std::cout << "The in-order traversal is: ";
        in(root);
        std::cout << std::endl;
    }

    void level_order() {
        DequeLinkedList<Node*> queue;
        queue.insert_right(root);
        std::cout << "The level-order traversal is: ";

        while (!queue.is_empty()) {
            Node* current = queue.delete_left();
            std::cout << current->data;
            queue.insert_right(current->left);
            queue.insert_right(current->right);
        }
        std::cout << std::endl;
    }

    void post_order() {
        std::cout << "The post-order traversal is: ";
        post(root);
        std::cout << std::endl;
    }

    void pre_order() {
        std::cout << "The pre-order traversal is: ";
        pre(root);
        std::cout << std::endl;
    }

    type sum() { return type(); }
};
