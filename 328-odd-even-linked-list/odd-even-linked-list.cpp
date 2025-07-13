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
1 → 3 → 5 → 2 → 4 → NULL
First iteration:
odd->next = even->next → 1->3
odd = odd->next → odd now points to 3
even->next = odd->next → 2->4
even = even->next → even now points to 4

Current state:
Odd: 1 → 3  
Even: 2 → 4  
Rest: 5 → NULL

Second iteration:
odd->next = even->next → 3->5
odd = odd->next → odd now points to 5
even->next = odd->next → 4->NULL
even = even->next → even now points to NULL

Final step:
odd->next = evenHead → attach even list (2 → 4) after odd list

Final list:
1 → 3 → 5 → 2 → 4 → NULL
✅ Output:
[1, 3, 5, 2, 4]
*/
