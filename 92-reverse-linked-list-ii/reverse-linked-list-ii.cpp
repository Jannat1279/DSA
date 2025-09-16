class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Base case: if the list is empty or has only one node, nothing to reverse
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        // Create a dummy node before head (helps simplify edge cases, e.g., reversing from position 1)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // 'prev' will point to the node just before the "left" position
        ListNode* prev = dummy;
        
        // Move 'prev' (left-1) steps forward, so it lands right before the sublist to reverse
        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        // 'curr' points to the first node of the sublist to be reversed
        ListNode* curr = prev->next;
        
        // Reverse the sublist between 'left' and 'right'
        for(int i = 1; i <= right - left; i++) {
            
            // 1. Take the node immediately after 'curr'
            ListNode* temp = prev->next;     // save the current first node of reversed part
            
            // 2. Move 'curr->next' to the front of the reversed part
            prev->next = curr->next;         // connect prev with the node after curr
            
            // 3. Fix 'curr' so it skips the moved node
            curr->next = curr->next->next;   // detach the moved node from curr
            
            // 4. Insert the moved node at the front of the reversed portion
            prev->next->next = temp;         // attach moved node before the old head of reversed part
        }
    
        // Return the new head (dummy->next accounts for cases when left == 1)
        return dummy->next;
    }
};
