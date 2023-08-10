/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* temp;
    bool check(ListNode* p) {
        if(p == NULL) return true;
        bool checkpalindrome = check(p->next) and (temp->val == p->val);
        temp = temp->next;
        return checkpalindrome;
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
};