/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 1: Create a hash map to store mapping from original node to
        // copied node
        unordered_map<Node*, Node*> mpp;

        Node* temp = head;

        // Step 2: First pass - create a copy of each node and store in map
        // This creates all the new nodes with the same values, but doesn't yet
        // link them
        while (temp != NULL) {
            Node* newNode =
                new Node(temp->val); // Create a new node with the same value
            mpp[temp] = newNode;     // Map original node to the new node
            temp = temp->next;       // Move to next node
        }

        temp = head;

        // Step 3: Second pass - set the 'next' and 'random' pointers of copied
        // nodes
        while (temp != NULL) {
            Node* copyNode = mpp[temp]; // Get the corresponding copied node

            // Set 'next' pointer of copied node to the copied version of
            // original's next
            copyNode->next = mpp[temp->next]; // Handles NULL automatically

            // Set 'random' pointer of copied node to the copied version of
            // original's random
            copyNode->random = mpp[temp->random]; // Also handles NULL

            temp = temp->next; // Move to next node
        }

        // Step 4: Return the head of the copied list (mapped from original
        // head)
        return mpp[head];
    }
};