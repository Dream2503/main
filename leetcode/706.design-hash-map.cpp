/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
    constexpr static int SIZE = 509;
    std::vector<std::list<std::pair<int, int>>> buckets;

    int hash(const int key) const { return key % SIZE; }

public:
    MyHashMap() : buckets(SIZE) {}

    void put(const int key, const int value) {
        const int idx = hash(key);

        for (auto& [first, second] : buckets[idx]) {
            if (first == key) {
                second = value;
                return;
            }
        }
        buckets[idx].emplace_back(key, value);
    }

    int get(const int key) const {
        const int idx = hash(key);

        for (auto& [first, second] : buckets[idx]) {
            if (first == key) {
                return second;
            }
        }
        return -1;
    }

    void remove(const int key) {
        const int idx = hash(key);
        int temp;

        for (auto& [first, second] : buckets[idx]) {
            if (first == key) {
                temp = second;
                break;
            }
        }
        buckets[idx].remove({key, temp});
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
