#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> inorderIndexMap;

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // Step 1: 前序的第一個值是 root
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Step 2: 找到 root 在中序的 index
        int rootIndex = inorderIndexMap[rootVal];

        // Step 3: 計算左子樹長度
        int leftSize = rootIndex - inStart;

        // Step 4: 遞迴建立左子樹
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                    inorder, inStart, rootIndex - 1);

        // Step 5: 遞迴建立右子樹
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, rootIndex + 1, inEnd);

        return root;
        }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

// Helper function: Level order traversal to print tree
void printTreeLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]\n";
        return;
    }

    vector<string> output;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr) {
            output.push_back(to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        } else {
            output.push_back("null");
        }
    }

    // Remove trailing "null"
    while (!output.empty() && output.back() == "null") {
        output.pop_back();
    }

    cout << "[";
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i];
        if (i != output.size() - 1) cout << ",";
    }
    cout << "]\n";
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Level Order Output: ";
    printTreeLevelOrder(root); // Should print [3,9,20,null,null,15,7]

    return 0;
}