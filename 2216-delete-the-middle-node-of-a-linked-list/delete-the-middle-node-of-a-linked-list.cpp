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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            // If there's only one node, delete it by returning nullptr
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            // It will store the slow
            prev = slow;
            slow = slow->next;
        }
        // Delete the middle node
        prev->next = slow->next;
        delete slow;
        return head;
    }
};

/*
Example:
head = [1, 2, 3, 4, 5]

First Iteration (in while loop):
fast moves to 3 (fast = fast->next->next)
prev = slow (points to 1)
slow moves to 2

Second Iteration:
fast moves to 5
prev = slow (now points to 2)
slow moves to 3

Third Iteration:
fast becomes nullptr (end of list)

Exit loop

Now:
slow points to node with value 3 (middle node)
prev points to 2

Deletion:

prev->next = slow->next;  // 2 now points to 4
delete slow;              // Deletes node 3

✅ Final Output Linked List:
[1, 2, 4, 5]
*/
