/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
    constexpr static int SIZE = 509;
    std::vector<std::list<int>> buckets;

    int hash(const int key) const { return key % SIZE; }

public:
    MyHashSet() : buckets(SIZE) {}

    void add(const int key) {
        const int idx = hash(key);

        for (const int val : buckets[idx]) {
            if (val == key) {
                return;
            }
        }
        buckets[idx].push_back(key);
    }

    void remove(const int key) {
        const int idx = hash(key);
        buckets[idx].remove(key);
    }

    bool contains(const int key) const {
        const int idx = hash(key);

        for (const int val : buckets[idx]) {
            if (val == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
