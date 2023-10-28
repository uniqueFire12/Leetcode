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
class BSTIterator {
    stack<TreeNode*> st;
    // reverse -> true -> before
    // reverse -> false -> after    
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmp = st.top();
        st.pop();
        if(!reverse)  pushAll(tmp->right);
        else  pushAll(tmp->left);
        return tmp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(TreeNode* root) {
        for(; root!=NULL ;) {
            st.push(root);
            if(reverse) {
                root = root -> right;
            }
            else {
                root = root ->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        // next
        BSTIterator l(root, false);
        // before
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        while(i<j) {
            if(i + j == k) 
                return true;
            else if(i + j < k) 
                i = l.next();
            else 
                j = r.next();
        }
        return false;
    }
};