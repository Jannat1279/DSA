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
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> visited;
        ListNode* current = head;

        // Traverse the list
        while (current != nullptr) {
            // If we've seen this node before, it's the start of the cycle
            if (visited.find(current) != visited.end()) {
                return current;
            }

            // Mark this node as visited
            visited.insert(current);
            current = current->next;
        }

        // If we reach here, there is no cycle
        return nullptr;
    }
};