class LRUCache {
public:
    class Node {
        public: 
        int key, value;
        Node* next, *prev;
        Node(int key, int value) {
            this->key = key; 
            this->value = value; 
            next = NULL; 
            prev = NULL; 
        }
    }; 

    int capacity; 
    unordered_map<int, Node*> cache; 

    Node* left = new Node(-1, -1); 
    Node* right = new Node(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        left->next = right;
        right->prev = left; 
        
    }

    void deleteNode(Node* node) {
        Node* prev = node->prev; 
        Node* next = node->next;

        prev->next = next; 
        next->prev = prev; 
    }

    void insertRight(Node* node) {
        Node* temp = right->prev;
        temp->next = node; 
        node->prev = temp; 

        node->next = right; 
        right->prev = node; 
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* currNode = cache[key];
        deleteNode(currNode); 
        insertRight(currNode); 
        
        return currNode->value; 
    }
    
    void put(int key, int value) {
        //check if in map 
        if (cache.find(key) != cache.end()) {
            Node* currNode = cache[key]; 
            deleteNode(currNode);
            Node* updatedNode = new Node(key, value); 
            insertRight(updatedNode);
            cache[key] = updatedNode; 
        }
        else {
            if(cache.size() == capacity) {
                //delete left end node 
                //insert right 
                Node* leftNode = left->next; 

                cache.erase(leftNode->key);
                deleteNode(leftNode); 
                Node* newNode = new Node(key, value); 
                cache[key] = newNode; 
                insertRight(newNode); 
            }
            else {
                //no need to delete 
                Node* newNode = new Node(key, value); 
                cache[key] = newNode; 
                insertRight(newNode); 
            }
        }

        //if not in map, check if full 
        //if full, pop
        //insert 
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */