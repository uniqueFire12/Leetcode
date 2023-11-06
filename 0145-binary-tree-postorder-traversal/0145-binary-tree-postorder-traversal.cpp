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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while(!st.empty() or cur != NULL) {
            if(cur != NULL) {
               st.push(cur);
               cur = cur->left;
            }
            else {
                TreeNode* temp = st.top()->right;
                if(temp == NULL) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() and temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);                       
                    }
                }
                else {
                    cur = temp;
                }
            }
        }
        return ans;
    }
};