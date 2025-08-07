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