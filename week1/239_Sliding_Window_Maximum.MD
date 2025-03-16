# 239. Sliding Window Maximum
Sliding Window Maximum（滑動窗口最大值）問題要求在 O(1) 時間複雜度內找到當前窗口內的最大值。最佳解法是使用 雙端隊列（Deque）來維護窗口內的最大值。
  
## Sliding Window Maximum 資料結構
使用 **雙向鏈表 Doubly Linked List** (std::list) + **哈希表 Hash table**(std::unordered_map) 來實作：

1. ```std::deque<int> windowDeque```
    * 存放數組索引，用來維護窗口內的最大值。
    * 遞減順序：確保隊首是當前窗口的最大值索引。
    * 插入與刪除 保持 O(1) 時間複雜度。

2. ```std::vector<int> result```
    * 用來存儲每個滑動窗口的最大值。
  
## 方法
1. ```void slide(int i, vector<int>& nums, int k, deque<int>& dq, vector<int>& result)```
   * 移除過期索引（超出窗口範圍）。
   * 維護單調遞減性（移除所有小於當前元素的索引）。
   * 將當前索引插入隊列。
   * 當窗口滿足大小時，將最大值（隊首元素）加入結果集。

2. ```vector<int> maxSlidingWindow(vector<int>& nums, int k)```
   * 初始化 deque<int> dq。
   * 遍歷 nums，對每個 i 調用 slide。
   * 回傳 result。
