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
        Node* temp = head;
        // Create an unordered_map to map original
        // nodes to their corresponding copied nodes
        unordered_map<Node*, Node*> mpp;

        // Step 1: Create copies of each node
        // and store them in the map
        while (temp != NULL) {
            // Create a new node with the
            // same data as the original node
            Node* newNode = new Node(temp->val);
            // Map the original node to its
            // corresponding copied node in the map
            mpp[temp] = newNode;
            // Move to the next node in the original list
            temp = temp->next;
        }

        temp = head;
        // Step 2: Connect the next and random
        // pointers of the copied nodes using the map
        while (temp != NULL) {
            // Access the copied node corresponding
            // to the current original node
            Node* copyNode = mpp[temp];
            // Set the next pointer of the copied node
            // to the copied node mapped to the
            // next node in the original list
            copyNode->next = mpp[temp->next];
            // Set the random pointer of the copied node
            // to the copied node mapped to the
            // random node in the original list
            copyNode->random = mpp[temp->random];
            // Move to the next node
            // in the original list
            temp = temp->next;
        }

        // Return the head of the
        // deep copied list from the map
        return mpp[head];
    }
};