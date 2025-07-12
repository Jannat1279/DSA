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

/*
Example:
head = [1, 2, 3, 4, 5]
n = 2

Initial State:
fast -> 1
slow -> 1
Move fast ahead by n = 2 steps:

i = 0: fast -> 2
i = 1: fast -> 3
Move both fast and slow one step until fast->next == NULL:

Iteration 1:
  fast -> 4
  slow -> 2

Iteration 2:
  fast -> 5
  slow -> 3
Now slow is at node 3. The next node (slow->next) is the one to delete (which is 4).

Delete node 4:

ListNode* delNode = slow->next;      // delNode -> 4
slow->next = delNode->next;          // slow->next -> 5
delete delNode;
✅ Final Linked List:
[1, 2, 3, 5]
*/
