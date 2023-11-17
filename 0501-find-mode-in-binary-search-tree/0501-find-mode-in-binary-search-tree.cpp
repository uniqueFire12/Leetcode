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
private:
    int current_val = 0;
    int current_cnt = 0;
    int max_cnt = 0;
    vector<int> ans;
    
    void inorder(TreeNode* root) {
        if(root == NULL) return;        
        
        inorder(root->left);       
        current_cnt = current_val == root->val ? current_cnt + 1 : 1;
        
        if(current_cnt == max_cnt) {
            ans.push_back(root->val);
        }
        else if(current_cnt > max_cnt) {
            max_cnt = current_cnt;
            ans = {root->val};
        }
        
        current_val = root->val;       
        inorder(root->right);
    }    
    
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};