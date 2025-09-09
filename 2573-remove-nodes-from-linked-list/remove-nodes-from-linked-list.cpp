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
    ListNode* removeNodes(ListNode* head) {
        // Base case: if the list is empty or has only one node,
        // return the head as no nodes need to be removed.
        if(head == nullptr || head->next == nullptr) 
            return head;

        // Recursive step: process the rest of the list
        ListNode* nextNode = removeNodes(head->next);

        // If the current node's value is less than the next node's value,
        // this node should be skipped (removed).
        if(head->val < nextNode->val) 
            return nextNode;

        // Otherwise, keep the current node and link it to the processed rest of the list
        head->next = nextNode;
        return head;
    }
};
