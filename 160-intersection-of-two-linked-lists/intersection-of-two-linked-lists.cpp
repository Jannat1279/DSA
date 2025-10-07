//time - O(m+n), space - O(1)

class Solution {
public:

    // Utility function to calculate the length of a linked list
    int getListLength(ListNode* head) {
        int len = 0;
        while (head != nullptr) {   // Traverse until the end
            len++;                  // Count nodes
            head = head->next;      // Move forward
        }
        return len;                 // Return total count
    }

    // Function to find the intersection node of two linked lists
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Step 1: Find lengths of both lists
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);

        // Step 2: Advance the longer list so both lists have equal remaining length
        while (lenA > lenB) {       // If list A is longer
            headA = headA->next;    // Move headA forward
            lenA--;                 // Reduce its length
        }

        while (lenB > lenA) {       // If list B is longer
            headB = headB->next;    // Move headB forward
            lenB--;                 // Reduce its length
        }

        // Step 3: Move both pointers one step at a time until they meet
        // If lists intersect, headA == headB at the intersection node
        // If not, both become nullptr simultaneously
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        // Step 4: Return either intersection node or nullptr (if no intersection)
        return headB;
    }
};
