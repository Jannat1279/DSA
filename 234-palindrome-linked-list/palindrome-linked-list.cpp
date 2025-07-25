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
    //     ListNode *reverseLinkedList(ListNode *head){
    //     if(head==NULL || head->next==NULL)return head;
    //     ListNode *newHead=reverseLinkedList(head->next);
    //     ListNode *front=head->next;
    //     front->next=head;
    //     head->next=NULL;
    //     return newHead;
    // }
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* current=head;
        ListNode* prev = NULL;
        while (current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next!= NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLinkedList(slow);
        ListNode* first = head;
        ListNode* second = newHead;
        while (second != NULL) {
            if (first->val != second->val) {
                // Changing back to the original state.
                reverseLinkedList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        // Changing back to the original state.
        reverseLinkedList(newHead);
        return true;
    }
};