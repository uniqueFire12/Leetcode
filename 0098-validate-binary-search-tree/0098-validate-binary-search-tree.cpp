/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, long long minVal, long long maxVal) {
        if(root == NULL) return true;
        
        if(root->val >= maxVal || root->val <= minVal) return false;
        
        return check(root->left, minVal, root->val)
               &&
               check(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        long long minVal = -1000000000000, maxVal = 1000000000000;
        return check(root, minVal, maxVal);
    }
};