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
    ListNode* partition(ListNode* head, int x) {
    // Create two dummy nodes for the "small" list and "large" list
    // small  → stores nodes with values < x
    // large  → stores nodes with values >= x
    ListNode* small  = new ListNode(0);
    ListNode* large  = new ListNode(0);
    
    // Pointers to build the two lists
    ListNode* smallP = small;
    ListNode* largeP = large;
    
    // Traverse the original list
    while (head) {
        if (head->val < x) {
            // Current node goes to the "small" list
            smallP->next = head;
            smallP = smallP->next; // Move pointer forward
        } else {
            // Current node goes to the "large" list
            largeP->next = head;
            largeP = largeP->next; // Move pointer forward
        }
        
        // Move to the next node in the original list
        head = head->next;
    }
    
    // Terminate the "large" list to avoid a possible cycle
    largeP->next = NULL;
    
    // Connect the "small" list with the "large" list
    smallP->next = large->next;
    
    // Return the head of the combined list (skip dummy node)
    return small->next;
}

};