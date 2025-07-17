/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    std::list<int> usage;
    int capacity;

public:
    LRUCache(const int capacity) : capacity(capacity) {}

    constexpr int get(const int key) noexcept {
        const auto itr = cache.find(key);

        if (itr == cache.end()) {
            return -1;
        }
        usage.erase(itr->second.second);
        usage.push_front(key);
        itr->second.second = usage.begin();
        return itr->second.first;
    }

    void put(const int key, const int value) noexcept {
        const auto itr = cache.find(key);

        if (itr != cache.end()) {
            usage.erase(itr->second.second);
        } else if (cache.size() == capacity) {
            const int lru = usage.back();
            usage.pop_back();
            cache.erase(lru);
        }
        usage.push_front(key);
        cache[key] = {value, usage.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
