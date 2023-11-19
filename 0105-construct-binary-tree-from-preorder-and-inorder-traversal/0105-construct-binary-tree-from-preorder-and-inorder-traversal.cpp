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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> &mpp) {
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = build(preorder, preStart+1, preStart+numsLeft,
                          inorder, inStart, inRoot-1, mpp);
        
        root->right = build(preorder, preStart+numsLeft+1, preEnd,
                          inorder, inRoot+1, inEnd, mpp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        int n = inorder.size();
        int m = preorder.size();
        for(int i=0; i<n; i++) {
            inMap[inorder[i]] = i;
        }
        
        TreeNode* root = build(preorder, 0, m-1, inorder, 0, n-1, inMap);
        return root;
    }
};