# 2366. Minimum Replacements to Sort the Array
取得一個 array數組 `nums` ，每次操作可以將一個元素拆分成兩個和相等的數。目標是讓數組變成非遞減順序，請求出最少需要幾次操作才能達成。

## 解題方法
使用 Greedy 來求解，時間複雜度為 O(n)。

1. 變數定義
   * `n`：紀錄array大小 `nums.size()` 。
   * `operations`：儲存拆分操作次數。
   * `prev`：紀錄右邊數字。

2. 程式邏輯
   * 只能拆分數字，不能交換順序，所以從右往左遍歷 `nums`，確保 `nums[i] ≤ nums[i+1]`。
   * 若 `nums[i] ≤ nums[i+1]`，則不需處理。
   * 若 `nums[i] > nums[i+1]`，則 nums[i] 需要拆分成`k`個部份，使得每個部分 `nums[i] ≤ nums[i+1]`。
   * 拆分次數為 `operations += (k - 1)`。
   * 更新 `prev`。
    
3. 拆分次數
   * k 為需要拆分成幾個部份。
   * C++ 整數除法會自動 向下取整 (floor)，但我們希望向上取整 (ceil)。
   * 若 `nums[i]` 是 `prev` 的倍數，則 `k = nums[i] / prev`。
   * 若 `nums[i]` 不是 `prev` 的倍數，則 `k` 需要多加 1 來確保拆分正確，也就是向上取整。
   * 向上取整：`k = (nums[i] + prev - 1) / prev`。

## 總結
1. 從右向左遍歷，確保 `nums[i] ≤ nums[i+1]`。
2. 若 `nums[i] > nums[i+1]`，則計算 `k = ceil(nums[i] / nums[i+1])`，拆分`k`個部份，使所有部分 `nums[i] ≤ nums[i+1]`。
3. 每次拆分需要 `k-1` 次操作，並更新 `prev = nums[i] / k`。
4. 如果無須拆分，也就是`nums[i] ≤ nums[i+1]`，更新 `prev = nums[i]`。