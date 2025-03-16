#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class LFUCache {
private:
    int capacity_;  // Maximum capacity of the cache
    int min_freq_;  // The current minimum frequency of any key in the cache

    unordered_map<int, pair<int, int>> keyToVal_; // key -> {value, frequency}
    unordered_map<int, list<int>> freqToKeys_; // frequency -> list of keys (Least Recently Used order)
    unordered_map<int, list<int>::iterator> keyIter_; // key -> iterator pointing to its position in freqToKeys_

public:
    LFUCache(int capacity) {
        capacity_ = capacity;
        min_freq_ = 0;
    }

    int get(int key) {
        if (keyToVal_.find(key) == keyToVal_.end()) {
            return -1; // Key not found in cache
        }
        updateFrequency(key); // Increase the frequency of the accessed key
        return keyToVal_[key].first; // Return the value
    }

    void put(int key, int value) {
        if (capacity_ == 0) return; // If capacity is zero, no operations can be performed

        // If key exists, update value and increase frequency
        if (keyToVal_.find(key) != keyToVal_.end()) {
            keyToVal_[key].first = value;
            updateFrequency(key);
            return;
        }

        // If cache is full, remove the least frequently used (LFU) and least recently used (LRU) key
        if (keyToVal_.size() >= capacity_) {
            int lfuKey = freqToKeys_[min_freq_].front(); // Get the least frequently used key
            freqToKeys_[min_freq_].pop_front(); // Remove from list
            if (freqToKeys_[min_freq_].empty()) {
                freqToKeys_.erase(min_freq_); // Remove empty frequency bucket
            }
            keyToVal_.erase(lfuKey); // Remove from key-value storage
            keyIter_.erase(lfuKey); // Remove iterator tracking
        }

        // Insert new key with frequency 1
        keyToVal_[key] = {value, 1};
        freqToKeys_[1].push_back(key);
        keyIter_[key] = --freqToKeys_[1].end();
        min_freq_ = 1; // Reset min_freq_ to 1
    }

private:
    void updateFrequency(int key) {
        int freq = keyToVal_[key].second; // Get the current frequency
        keyToVal_[key].second++; // Increase frequency

        // Remove key from its current frequency list
        freqToKeys_[freq].erase(keyIter_[key]);
        if (freqToKeys_[freq].empty()) {
            freqToKeys_.erase(freq); // Remove empty frequency bucket
            if (min_freq_ == freq) min_freq_++; // Update min_freq_ if necessary
        }

        // Insert key into the new frequency list
        freqToKeys_[freq + 1].push_back(key);
        keyIter_[key] = --freqToKeys_[freq + 1].end();
    }
};