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
