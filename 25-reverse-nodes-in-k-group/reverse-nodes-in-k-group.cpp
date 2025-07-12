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