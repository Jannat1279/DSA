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
    ListNode* oddEvenList(ListNode* head) {
        // Edge case: if list is empty or has only one node, no rearrangement
        // needed
        if (head == NULL || head->next == NULL)
            return head;

        // Initialize pointers:
        // 'odd' will track the end of the odd-indexed node list
        ListNode* odd = head;

        // 'even' will track the end of the even-indexed node list
        ListNode* even = head->next;

        // Store the head of the even list to attach it later after odd list
        ListNode* evenHead = even;

        // Traverse the list while there are at least two more nodes to process
        while (even != NULL && even->next != NULL) {
            // Link the next odd node (skip one node)
            odd->next = even->next;
            odd = odd->next;

            // Link the next even node (skip one node)
            even->next = odd->next;
            even = even->next;
        }

        // After separating, link the end of odd list to the start of even list
        odd->next = evenHead;

        // Return the rearranged list starting from head
        return head;
    }
};

/*
Example:
Value:  1 → 2 → 3 → 4 → 5

Step 1: Initialization
odd = head (1)
even = head->next (2)
evenHead = 2 (so we can connect later)

Step 2: First Iteration
odd->next = even->next → 1->3
Move odd = 3
Now list looks like:
1 → 3 → 4 → 5 → NULL
and even part still connected as:
2 → 4 → 5 → NULL
even->next = odd->next → 2->4
Move even = 4

Step 3: Second Iteration
odd->next = even->next → 3->5
Move odd = 5
Now odd part looks like:
1 → 3 → 5 → NULL
even->next = odd->next → 4->NULL
Move even = NULL (loop ends)

Step 4: Attach Even List
Connect odd’s tail (5) to evenHead (2)

Final rearranged list:
1 → 3 → 5 → 2 → 4 → NULL
*/
