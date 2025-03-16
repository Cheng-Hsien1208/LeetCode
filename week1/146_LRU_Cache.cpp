#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity_;  // Maximum capacity of the cache
    std::list<std::pair<int, int>> cacheList_;  // Doubly linked list to store key-value pairs
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap_; // Hash table mapping keys to list iterators

public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = cacheMap_.find(key);
        if (it == cacheMap_.end()) {
            return -1;  // Key is not found in the cache
        }

        // Move the accessed node to the front of the list (most recently used)
        cacheList_.splice(cacheList_.begin(), cacheList_, it->second);
        return it->second->second;  // Return the corresponding value
    }

    void put(int key, int value) {
        auto it = cacheMap_.find(key);
        if (it != cacheMap_.end()) {
            // Key already exists, update its value
            it->second->second = value;
            // Move the node to the front of the list (most recently used)
            cacheList_.splice(cacheList_.begin(), cacheList_, it->second);
        } 
        else {
            // If the cache is full, remove the least recently used (LRU) item
            if (cacheList_.size() == capacity_) {
                auto last = cacheList_.back();  // Get the last element (LRU key-value)
                cacheMap_.erase(last.first);   // Remove it from the hash table
                cacheList_.pop_back();         // Remove it from the list
            }
            
            // Insert the new key-value pair at the front (most recently used)
            cacheList_.emplace_front(key, value);
            cacheMap_[key] = cacheList_.begin();
        }
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    std::cout << lru.get(1) << std::endl; // 1
    lru.put(3, 3); // Evicts key=2
    std::cout << lru.get(2) << std::endl; // -1 (not found)
    lru.put(4, 4); // Evicts key=1
    std::cout << lru.get(1) << std::endl; // -1 (not found)
    std::cout << lru.get(3) << std::endl; // 3
    std::cout << lru.get(4) << std::endl; // 4
    return 0;
}
