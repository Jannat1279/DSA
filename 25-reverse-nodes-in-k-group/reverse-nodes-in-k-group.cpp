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
    // Helper function to calculate the length of the linked list
    int lengthOfLinkedList(ListNode* head) {
        int length = 0;
        ListNode* temp = head;

        // Traverse the list and count the nodes
        while (temp != NULL) {
            temp = temp->next;
            length++;
        }

        return length;
    }

    // Helper function to reverse k nodes in the linked list
    ListNode* reverseKGroup(ListNode* head, int k, int length) {
        // If remaining nodes are fewer than k, do not reverse
        if (length < k) {
            return head;
        }

        // Initialize pointers for reversal
        int count = 0;
        ListNode* prev = NULL;
        ListNode* nex = NULL;
        ListNode* curr = head;

        // Reverse k nodes
        while (count < k && curr != NULL) {
            nex = curr->next;  // Save next node
            curr->next = prev; // Reverse current node's pointer
            prev = curr;       // Move prev to current
            curr = nex;        // Move to next node
            count++;
        }

        // Recursively reverse the next k-group and connect to the current
        // reversed group
        if (nex != NULL) {
            head->next = reverseKGroup(nex, k, length - k);
        }

        // prev becomes the new head of the reversed group
        return prev;
    }

    // Main function to reverse nodes in k-group
    ListNode* reverseKGroup(ListNode* head, int k) {
        // First, calculate the length of the linked list
        int length = lengthOfLinkedList(head);

        // Call the helper function to start k-group reversal
        return reverseKGroup(head, k, length);
    }
};

/*
Example:
head = [1, 2, 3, 4, 5]
k = 2

Step 1: Calculate length
lengthOfLinkedList([1,2,3,4,5]) = 5

🌀 Recursive Reversal Call 1:
Input: head = 1, length = 5, k = 2
Group: [1, 2]

Reverse: 1 → 2 becomes 2 → 1
Remaining list: [3, 4, 5]

Call recursive on reverseKGroup(3, 2, 3)
Attach: 1->next = result of reverseKGroup(3...)

🌀 Recursive Reversal Call 2:
Input: head = 3, length = 3, k = 2
Group: [3, 4]

Reverse: 3 → 4 becomes 4 → 3
Remaining list: [5]

Call recursive on reverseKGroup(5, 2, 1)
Attach: 3->next = result of reverseKGroup(5...)

🚫 Recursive Reversal Call 3 (Base Case):
Input: head = 5, length = 1, k = 2
Since length < k, return head as is (no reversal)

🔚 Combining the results:
From call 2:
Reversed [3, 4] becomes [4, 3], with 3->next = 5
From call 1:
Reversed [1, 2] becomes [2, 1], with 1->next = 4

✅ Final Output:
[2, 1, 4, 3, 5]

*/
