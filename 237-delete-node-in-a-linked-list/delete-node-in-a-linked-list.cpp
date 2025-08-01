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
    void deleteNode(ListNode* node) {
        // val to be deleted
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
/*
A → B → C → D → NULL
    ↑
   node to delete

node->val = node->next->val;
A->C->C->D (value got copied)

node->next=node->next->next
A->C->D
*/
