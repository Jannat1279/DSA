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
    // bool hasCycle(ListNode *head) {
    //     set<ListNode*> sLL;
    //     ListNode *curr=head;
    //     while(curr!=NULL){
    //         if(sLL.contains(curr))return true;
    //         sLL.insert(curr);
    //         curr=curr->next;
    //     }
        
    //     return false;
    // }

    bool hasCycle(ListNode *head) {
        ListNode* slow = head; // Tortoise
        ListNode* fast = head; // Hare

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // Move 1 step
            fast = fast->next->next;     // Move 2 steps

            if (slow == fast) {
                return true;             // Cycle detected
            }
        }

        return false; // No cycle
    }
};

/*
Example:
1 → 2 → 3 → 4 → 5
          ↑     ↓
           ← ← ←

Step 1: slow = 2, fast = 3

Step 2: slow = 3, fast = 5

Step 3: slow = 4, fast = 3

Step 4: slow = 5, fast = 5 ✅ They meet — cycle detected
*/
