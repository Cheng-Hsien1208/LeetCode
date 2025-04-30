#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxSum = INT_MIN;

    // Helper function to compute max gain from a node
    int maxGain(TreeNode* node) {
        if (!node) return 0;

        // Recursively compute left and right gains
        int leftGain = max(maxGain(node->left), 0);   // If negative, treat as 0
        int rightGain = max(maxGain(node->right), 0);

        // Current path includes both left and right subtrees
        int currentPath = node->val + leftGain + rightGain;

        // Update the global max path sum
        maxSum = max(maxSum, currentPath);

        // Return the max one-side path (important for parent recursion)
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

TreeNode* buildExample1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

TreeNode* buildExample2() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;

    TreeNode* root1 = buildExample1();
    cout << "Example 1 Max Path Sum: " << sol.maxPathSum(root1) << endl; // Output: 6

    sol = Solution(); // Reset
    TreeNode* root2 = buildExample2();
    cout << "Example 2 Max Path Sum: " << sol.maxPathSum(root2) << endl; // Output: 42

    return 0;
}
