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
    TreeNode* build(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> &mpp) {
        if(postStart > postEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = build(postorder, postStart, postStart+numsLeft-1, 
                          inorder, inStart, inRoot-1, mpp);
        root->right = build(postorder, postStart+numsLeft, postEnd-1, 
                          inorder, inRoot+1, inEnd, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        int n = inorder.size();
        int m = postorder.size();
        for(int i=0; i<n; i++) {
            inMap[inorder[i]] = i;
        }
        
        TreeNode* root = build(postorder, 0, m-1, inorder, 0, n-1, inMap);
        return root;
    }
};