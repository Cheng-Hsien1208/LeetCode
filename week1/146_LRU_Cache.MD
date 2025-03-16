# 146. LRU Cache
全名為 Least Resently Used Cache，當有新的資料要存入 cache 但其空間不夠時，丟棄調最久沒使用的資料。  
本題要求 O(1) 時間複雜度 來實作 get(key) 和 put(key, value)。

## LRUCache class
* ```LRUCache(int capacity)```：初始化 LRUCache 並給定一個正整數的 capacity。
* ```int get(int key)```：如果 key 存在則回傳其 value，不存在則回傳 -1。
* ```void put(int key, int value)```：
  * 如果 key 存在，則更新其對應的值。
  * 如果 key 不存在，則將該 key-value 對新增到快取中。
  * 如果此操作導致快取中的鍵數量超過 capacity，則移除最久未使用的鍵。
  
## LRUCache 設計
使用 **雙向鏈表 Doubly Linked List** (std::list) + **哈希表 Hash table**(std::unordered_map) 來實作：

1. ```std::list<pair<int, int>> cacheList```
    * 使用 雙向鏈表（Doubly Linked List）來維護 LRU 順序。
    * 頭部 (begin()) 是最新使用的，尾部 (back()) 是最久未使用的。

2. ```std::unordered_map<int, list<pair<int, int>>::iterator> cacheMap```
    * 使用 哈希表 來儲存 key → list iterator，確保 O(1) 查找。
  
## 方法
1. ```int get(int key)```
   * 若 key 存在：
       1. 將節點移動到 list 頭部（表示最近使用）。
       2. 回傳對應的值。
   * 若 key 不存在，回傳 -1。

2. ```void put(int key, int value)```
   * 若 key 存在：
       1. 更新 value。
       2. 將該節點移動到 list 頭部（最近使用）。
   * 若 key 不存在：若
       1. cacheList 滿了，刪除 list 尾部節點（最久未使用的）。
       2. 新增 key-value 到 list 頭部。
       3. 更新 cacheMap[key] 指向 list.begin()。