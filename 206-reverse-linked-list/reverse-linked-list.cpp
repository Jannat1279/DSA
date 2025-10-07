// time - O(n), space - O(1)


class Solution {
public:
    // Function to reverse a singly linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;    // Current node we're visiting
        ListNode* prev = nullptr; // Previous node (starts as NULL)

        // Loop through the list
        while (curr != nullptr) {
            ListNode* next = curr->next; // Save the next node
            curr->next = prev;           // Reverse the current node's pointer
            prev = curr;                 // Move prev to current
            curr = next;                 // Move to next node
        }

        // At the end, prev points to the new head
        return prev;
    }
};

/*
Example:

Suppose the list is:
1 -> 2 -> 3 -> 4 -> NULL

Steps during iteration:
Reverse 1 -> NULL, prev = 1, curr = 2
Reverse 2 -> 1, prev = 2, curr = 3
Reverse 3 -> 2 -> 1, prev = 3, curr = 4
Reverse 4 -> 3 -> 2 -> 1, prev = 4, curr = NULL

Finally, return prev (which is node 4), giving:
4 -> 3 -> 2 -> 1 -> NULL
*/
