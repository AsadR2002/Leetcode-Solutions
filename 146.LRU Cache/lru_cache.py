class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val 
        self.prev = self.next = None 

class LRUCache(object):

    def __init__(self, capacity):
        self.cap = capacity 
        self.cache = {}
        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left 
        """
        :type capacity: int
        """
        
    def remove(self, node):
        prev, nxt = node.prev, node.next 
        nxt.prev, prev.next = prev, nxt
    
    def insert(self, node): 
        right = self.right 
        prev = right.prev 
        prev.next, right.prev = node, node
        node.next, node.prev = right, prev


    def get(self, key):
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1
        """
        :type key: int
        :rtype: int
        """
        

    def put(self, key, value):
        if key in self.cache: 
            self.remove(self.cache[key])
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        if len(self.cache) > self.cap:
            #remove and delete LRU from hashmap
            lru = self.left.next 
            self.remove(lru)
            del self.cache[lru.key]


        """
        :type key: int
        :type value: int
        :rtype: None
        """
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)