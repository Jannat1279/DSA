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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Initialize two pointers - both start at the head of the list
        ListNode* fast = head;
        ListNode* slow = head;

        // Move the fast pointer 'n' steps ahead
        // This creates a gap of 'n' nodes between fast and slow
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast is NULL, it means we need to remove the head node
        if (fast == NULL) {
            return head->next;
        }

        // Move both fast and slow one step at a time
        // When fast reaches the last node, slow will be just before the target
        // node
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the target node
        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;

        // Return the head of the modified list
        return head;
    }
};