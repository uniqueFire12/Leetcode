/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp=head,*temp1,*ans;
        
        unordered_map<Node* , Node*> up;
        
        while(temp != NULL)
        {
            temp1 = new Node(temp->val);
            up.insert({temp,temp1});
            temp = temp->next;
        }
        
        temp = head;
        temp1 = up[head];
        
        while(temp!=NULL)
        {
            temp1->next=up[temp->next];
            temp1->random=up[temp->random];
            temp=temp->next;
            temp1=temp1->next;
        }
        
        ans = up[head];
        return ans;
    }
};