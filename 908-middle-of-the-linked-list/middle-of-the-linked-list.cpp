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
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers at the head:
        // 'slow' moves one step at a time, 'fast' moves two steps
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list until 'fast' reaches the end
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // Move slow by one node
            fast = fast->next->next; // Move fast by two nodes
        }

        // When the loop ends, 'slow' will be at the middle node
        return slow;
    }
};