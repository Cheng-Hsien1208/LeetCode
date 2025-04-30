#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            // Base case
            if (root == nullptr || root == p || root == q)
                return root;
    
            // Search in left and right subtree
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
            // If both sides return non-null, current root is the LCA
            if (left && right)
                return root;
    
            // Otherwise, return the non-null side
            return left ? left : right;
        }
    };

int main() {
    // Construct the tree manually
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution sol;
    TreeNode* p = root->left;           // 5
    TreeNode* q = root->right;          // 1
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    return 0;
}