class LRUCache {
public:
    // Node class for doubly linked list
    class node {
    public:
        int key, value;
        node* prev;
        node* next;

        // Constructor to initialize a node with key-value pair
        node(int key, int value) {
            this->key = key;       // Use 'this->' to avoid shadowing constructor parameters
            this->value = value;
        }
    };

    // Pointers to dummy head and tail nodes for the doubly linked list
    node* head = new node(-1, -1);  // Dummy head
    node* tail = new node(-1, -1);  // Dummy tail

    int cap; // Maximum capacity of the cache

    // Hash map to store key → pointer to the node in the list
    unordered_map<int, node*> m;

    // Constructor: Initializes capacity and links head and tail
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Adds a new node right after head (most recently used position)
    void addNode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // Deletes a node from the doubly linked list
    void delNode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    // Retrieves the value of the key if it exists in the cache
    // Also marks the node as most recently used
    int get(int key) {
        if (m.find(key) != m.end()) {
            node* resnode = m[key];       // Get node from map
            int res = resnode->value;     // Store its value
            m.erase(key);                 // Remove from map temporarily
            delNode(resnode);             // Remove node from current position
            addNode(resnode);             // Add node to front
            m[key] = head->next;          // Update map with new front position
            return res;
        }
        return -1;  // Key not found
    }

    // Inserts or updates the key-value pair in the cache
    void put(int key, int value) {
        // If key already exists, remove the existing node
        if (m.find(key) != m.end()) {
            node* existingnode = m[key];
            m.erase(key);
            delNode(existingnode);
        }

        // If capacity is full, remove the least recently used node (before tail)
        if (m.size() == cap) {
            m.erase(tail->prev->key);   // Remove from map
            delNode(tail->prev);        // Remove from list
        }

        // Add new node to the front (most recently used)
        addNode(new node(key, value));
        m[key] = head->next;  // Update map to point to the new front node
    }
};
