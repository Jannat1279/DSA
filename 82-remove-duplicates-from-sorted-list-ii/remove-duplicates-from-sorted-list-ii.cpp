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
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node before the head to handle edge cases
        // (like when the first few nodes are duplicates)
        ListNode* newHead = new ListNode(0, head);

        // 'prev' points to the last node in the result list
        ListNode* prev = newHead;

        // Traverse the list
        while (head != NULL) {
            // Case 1: current node has duplicates ahead
            if (head->next != NULL && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
                // Connect prev->next to the node after duplicates
                prev->next = head->next;
            }
            // Case 2: current node is unique
            else {
                // Move 'prev' forward (include this node in the result)
                prev = prev->next;
            }
            // Always move 'head' forward
            head = head->next;
        }

        // Return the real head (next of dummy node)
        return newHead->next;
    }
};
