// time - O(m+n), space - O(m+n)=O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node (sentinel node) to simplify edge cases
        ListNode* returnHead = new ListNode(-1);

        // Keep a pointer to the head of merged list (needed for returning result later)
        ListNode* headNode = returnHead;

        // Traverse both lists until one becomes empty
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                // If list1 node is smaller, attach it to merged list
                returnHead->next = list1;
                list1 = list1->next; // Move list1 forward
            } else {
                // If list2 node is smaller, attach it to merged list
                returnHead->next = list2;
                list2 = list2->next; // Move list2 forward
            }
            // Move the merged list pointer forward
            returnHead = returnHead->next;
        }

        // At this point, one of the lists is exhausted.
        // Directly connect the remaining non-empty list (if any).
        if (list1 == nullptr) {
            returnHead->next = list2;
        } else if (list2 == nullptr) {
            returnHead->next = list1;
        }

        // The first node is dummy (-1), so skip it and return actual head
        return headNode->next;
    }
};
