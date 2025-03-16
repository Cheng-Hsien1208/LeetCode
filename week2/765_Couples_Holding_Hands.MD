# 765. Couples Holding Hands
有 `n` 對情侶坐在 `2n` 個座位上，座位按一排排列，`row[i]` 代表坐在第 `i` 個座位上的人的編號。每對情侶的編號是 `(0,1), (2,3), (4,5) ⋯` 為一組，但座位上的順序是混亂的。  
目標是讓所有情侶都坐在一起，每次操作可以交換任意兩個人的座位，請計算最少需要多少次交換才能達成目標。 

## 解題方法
*  判斷情侶是否坐在一起
   * 每個人的情侶 ID 是 `x ^ 1`（XOR 運算可快速找出配對的 ID）。
   * 只要 `row[i] ^ 1 == row[i+1]`，表示這對情侶已經坐在一起，不需要交換。

* Greedy + Position Mapping
   1. 建立一個 position 陣列，用來記錄每個人當前所在的座位位置 `vector<int> position(n)`。
   2. 遍歷每一對座位 (i, i+1)。
       * 取得 row[i] 應該配對的情侶 ID：partner = row[i] ^ 1
       * 如果 row[i+1] != partner，說明這對情侶沒有坐在一起，需要交換
    
* 執行 swap 並更新 Position Mapping
   * 找到 `partner` 目前所在的座位 `partnerIndex`
   * 交換 `row[i+1]` 和 `row[partnerIndex]`
   * 更新 `position` 陣列，確保索引正確

* 時間複雜度
  * 建立 position 陣列：`O(n)`
  * 遍歷 row 進行交換：`O(n)`
  * 總體時間複雜度：`O(n)`

## 總結
這題的核心是 **Greedy + Position Mapping**，透過 XOR 快速尋找情侶，利用 position 陣列來記錄座位索引，並透過 **交換 + 更新索引** 來達到最少交換次數。