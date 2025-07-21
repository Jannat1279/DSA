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

/*
Example:

LRUCache* cache = new LRUCache(2); // capacity = 2

cache->put(1, 1);  // cache = {1=1}
cache->put(2, 2);  // cache = {2=2, 1=1}
cache->get(1);     // returns 1, cache = {1=1, 2=2}
cache->put(3, 3);  // evicts key 2, cache = {3=3, 1=1}
cache->get(2);     // returns -1 (not found)
cache->put(4, 4);  // evicts key 1, cache = {4=4, 3=3}
cache->get(1);     // returns -1 (not found)
cache->get(3);     // returns 3
cache->get(4);     // returns 4
🧠 Step-by-Step Explanation:
✅ put(1, 1)
Cache: {1=1} → Only one item, no eviction.

✅ put(2, 2)
Cache: {2=2, 1=1}
Most recently used = 2 (front), least recently used = 1 (back)

✅ get(1) → returns 1
Key 1 exists.
Move 1 to front (most recently used).
Cache: {1=1, 2=2}

✅ put(3, 3)
Cache is full.
Evict LRU (key 2).
Insert key 3 to front.
Cache: {3=3, 1=1}

✅ get(2) → returns -1
Key 2 was evicted → not found.

✅ put(4, 4)
Cache is full.
Evict LRU (key 1).
Insert key 4 to front.
Cache: {4=4, 3=3}

✅ get(1) → returns -1
Key 1 was evicted → not found.

✅ get(3) → returns 3
Key 3 exists → move to front.
Cache: {3=3, 4=4}

✅ get(4) → returns 4
Key 4 exists → move to front.
Cache: {4=4, 3=3}

✅ Final Output Sequence:
get(1) → 1  
get(2) → -1  
get(1) → -1  
get(3) → 3  
get(4) → 4
*/
