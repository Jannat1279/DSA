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
l1 = [2 → 4 → 3]   // represents the number 342
l2 = [5 → 6 → 4]   // represents the number 465

=> Output list = [7 → 0 → 8]

Step-by-step execution:
Initialization:
result = new ListNode(0) → dummy head
ptr = result (points at dummy node)
carry = 0

Iteration 1:
l1->val = 2, l2->val = 5, carry = 0
sum = 2 + 5 + 0 = 7
carry = 7 / 10 = 0, sum = 7 % 10 = 7
Create new node 7, attach after result.
ptr = 7, advance l1 = 4, l2 = 6.
List so far: dummy → 7

Iteration 2:
l1->val = 4, l2->val = 6, carry = 0
sum = 4 + 6 + 0 = 10
carry = 10 / 10 = 1, sum = 10 % 10 = 0
Create new node 0, attach.
ptr = 0, advance l1 = 3, l2 = 4.
List so far: dummy → 7 → 0

Iteration 3:
l1->val = 3, l2->val = 4, carry = 1
sum = 3 + 4 + 1 = 8
carry = 8 / 10 = 0, sum = 8 % 10 = 8
Create new node 8, attach.
ptr = 8, advance l1 = null, l2 = null.

List so far: dummy → 7 → 0 → 8

After loop:
Both l1 and l2 are null.

carry = 0, so no extra node.
*/
