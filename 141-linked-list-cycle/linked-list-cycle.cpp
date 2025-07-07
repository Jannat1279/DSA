/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> sLL;
        ListNode *curr=head;
        while(curr!=NULL){
            if(sLL.contains(curr))return true;
            sLL.insert(curr);
            curr=curr->next;
        }
        
        return false;
    }
};