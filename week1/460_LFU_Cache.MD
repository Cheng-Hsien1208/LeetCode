# 460. LFU Cache
全名為 Least Frequently Used Cache，當有新的資料要存入 cache 但其空間不夠時，會丟棄使用頻率最少的資料。  
如果有多個 key 使用頻率相同，則會淘汰最久未使用的 key（LRU 機制）。  
本題要求 O(1) 時間複雜度 來實作 get(key) 和 put(key, value)。

## LFUCache class
* ```LFUCache(int capacity)```：初始化 `LFUCache` 並給定一個正整數的 `capacity`。
* ```int get(int key)```：
  * 若 `key` 存在，則回傳對應的 `value`，並增加其使用頻率。
  * 若 `key` 不存在，回傳 `-1`。
* ```void put(int key, int value)```：
  * 如果 `key` 已存在，則更新其 `value`，並提升頻率。
  * 如果 `key` 不存在：
    1. 如果 `cache` 已滿，則移除最少使用 (LFU) 且最久未使用 (LRU) 的 `key`。
    2. 新增 `key-value` 到 `cache`，並設定初始頻率為 `1`。
  
## LFUCache 設計
使用 **雙向鏈表 Doubly Linked List** (std::list) + **哈希表 Hash table**(std::unordered_map) + 頻率表 (std::map) 來實作：

1. ```std::unordered_map<int, pair<int, int>> key_to_val```
    * 儲存 `key → {value, frequency}`。
    * 透過 `key` 取得其對應的 `value` 和 `frequency`。

2. ```std::unordered_map<int, std::list<int>> freq_to_keys```
    * `frequency → list<int>`，維護所有擁有相同頻率的 `key`。
    * `list<int>` 內部的順序維持 LRU。
  
3. ```std::unordered_map<int, std::list<int>::iterator> key_iter```
    * 記錄 `key` 在 `freq_to_keys[freq]` 對應 `list` 的 `iterator`，用於 O(1) 快速刪除和移動 `key`。
  
4. ```int min_freq```：當前 cache 內的最小使用頻率，當刪除 key 時可快速找到 LFU key。
   
  
## 方法
1. ```int get(int key)```
   * 若 `key` 存在：
       1. 提升 `key` 的使用頻率。
       2. 將 `key` 從舊頻率的 list 移除，並加入新頻率的 list。
       3. 更新 `min_freq`（若有必要）。
       4. 回傳 `value。`
   * 若 `key` 不存在，回傳 `-1`。

2. ```void put(int key, int value)```
   * 若 `key` 存在：
       1. 更新其 `value。`
       2. 呼叫 `update_freq(key)` 來增加頻率。
   * 若 key 不存在：
       1. 如果 cache 已滿：
          * 找到 `freq_to_keys[min_freq]` 最久未使用的 key 並刪除。
          * 刪除 `key_to_val` 和 `key_iter` 中的對應項目。
       2. 新增 `key-value`，頻率設為 1，並更新 `min_freq = 1`。
