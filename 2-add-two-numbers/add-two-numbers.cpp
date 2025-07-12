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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Create a dummy node to build the result list
    ListNode* result = new ListNode(0);
    ListNode* ptr = result;

    int carry = 0; // Initialize carry to 0

    // Traverse both lists until both are exhausted
    while (l1 != nullptr || l2 != nullptr) {
        int sum = carry; // Start with the carry from previous addition

        // Add value from the first list if available
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        // Add value from the second list if available
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Update carry for next iteration
        carry = sum / 10;
        sum = sum % 10;

        // Create a new node with the current digit and attach it to result
        ptr->next = new ListNode(sum);
        ptr = ptr->next;
    }

    // If there's a carry left, add a new node for it
    if (carry == 1) {
        ptr->next = new ListNode(1);
    }

    // Return the actual result list (skipping dummy head)
    return result->next;

    }
};

/*
Example:
l1 = [2, 4, 3]   // Represents the number 342
l2 = [5, 6, 4]   // Represents the number 465

342 + 465 = 807
Output: [7, 0, 8] (since digits are stored in reverse order)

Initial:
result → dummy node with value 0
ptr → result
carry = 0

1st Iteration:
l1->val = 2, l2->val = 5, carry = 0
sum = 2 + 5 + 0 = 7
carry = 0, sum = 7
Add node with value 7

2nd Iteration:
l1->val = 4, l2->val = 6, carry = 0
sum = 4 + 6 + 0 = 10
carry = 1, sum = 0
Add node with value 0

3rd Iteration:
l1->val = 3, l2->val = 4, carry = 1
sum = 3 + 4 + 1 = 8
carry = 0, sum = 8
Add node with value 8

Final:
Both lists exhausted and carry = 0, so no extra node needed.

[7, 0, 8] → which represents 807

*/
