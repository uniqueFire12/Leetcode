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
    int check(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lst = check(root->left);
        int rst = check(root->right);
        
        if(lst == -1 || rst == -1) return -1;
        if(abs(lst - rst) > 1) return -1;
        
        return max(lst, rst) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};