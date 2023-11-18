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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> hashMap;
        
        for(int i=0; i<inorder.size(); i++) {
            hashMap[inorder[i]] = i;
        }
        
        TreeNode* root = buildItActually(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, hashMap);
        
        return root;
    }
    
    TreeNode* buildItActually(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> &mpp) {
        if(preStart > preEnd or inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = buildItActually(preorder, preStart+1, preStart+numsLeft, 
                                     inorder, inStart, inRoot-1, mpp);
            
        root->right = buildItActually(preorder, preStart+ numsLeft+1, preEnd, 
                                      inorder, inRoot+1, inEnd, mpp);
        
        return root;
    }
};