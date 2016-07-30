// Implemeent LRU cache. LRU(capacity).
// That is element that is accessed recent, should be popped out last of the cache.
//
// SOLUTION:
// Only thing that we need to take care is, what if element is already there, then we need to remove
// it from its current position and put it on the end of the queue.
//
// Use a combination of DoublyLinkedList and HashMap. HashMap stores key -> node in doubly linked list.
// If present in map, remove from doubly linked list, u have access to the node and then put it an the end (or first, whatever terminology you use).
class Node {
    int key;
    int data;
    Node previous;
    Node next;
}

class LRUCache {
 
    private int capacity;
    private Map<Integer, Node> data;
    private Node head;
    private Node end;
 
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.data = new HashMap<>();
    }
}

private void add(Node node) {
 
    // Reset position
    node.next = null;
    node.previous = null;
 
    // First element
    if (null == this.head) {
        this.head = node;
        this.end = node;
        return;
    }
 
    // Existing element
    this.head.previous = node;
    node.next = this.head;
    this.head = node;
}

private void remove(Node node) {
 
    // Nothing to do
    if (this.head == null || null == node) {
        return;
    }
 
    // The only one item
    if (this.head == this.end && this.head == node) {
        this.head = null;
        this.end = null;
        return;
    }
 
    // Remove from head
    if (node == this.head) {
        this.head.next.previous = null;
        this.head = this.head.next;
        return;
    }
 
    // Remove from end
    if (node == this.end) {
        this.end.previous.next = null;
        this.end = this.end.previous;
        return;
    }
 
    // Remove in the middle
    node.previous.next = node.next;
    node.next.previous = node.previous;
 
}

private void moveFirst(Node node) {
    this.remove(node);
    this.add(node);
}
 
private void removeLast() {
    this.remove(this.end);
}


public int get(int key) {
 
        // Existing key
        if (this.data.containsKey(key)) {
 
            // Move to first place
            Node node = this.data.get(key);
            this.moveFirst(node);
 
            // Return the value
            return node.data;
        }
 
        // Not found
        return -1;
    }


public void set(int key, int value) {
 
    // Existing slot
    if (this.data.containsKey(key)) {
        Node node = this.data.get(key);
        this.moveFirst(node);
        node.data = value;
        return;
    }
 
    // Out of capacity, cleaning the oldest slot
    if (this.data.size() >= this.capacity) {
        int id = this.end.key;
        this.removeLast();
        this.data.remove(id);
    }
 
    // New slot
    Node node = new Node();
    node.key = key;
    node.data = value;
    this.add(node);
    this.data.put(key, node);
}
