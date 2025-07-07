/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//     ListNode* detectCycle(ListNode* head) {
//         unordered_set<ListNode*> visited;
//         ListNode* current = head;

//         // Traverse the list
//         while (current != nullptr) {
//             // If we've seen this node before, it's the start of the cyclei
//             if (visited.find(current) != visited.end()) {
//                 return current;
//             }

//             // Mark this node as visited
//             visited.insert(current);
//             current = current->next;
//         }

//         // If we reach here, there is no cycle
//         return nullptr;
//     }

ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect cycle using slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast) {
                // Phase 2: Find the entry point of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Entry point of cycle
            }
        }

        // No cycle found
        return nullptr;
}
};

/*
Floyd's Cycle Detection + Entry Point Algorithm
🔁 Phase 1: Detect if a cycle exists
Use two pointers:
slow moves one step at a time
fast moves two steps at a time
If they meet, a cycle is present

🎯 Phase 2: Find the start of the cycle
Reset one pointer to the head
Move both slow and fast one step at a time
The node where they meet is the entry point of the cycle
*/
