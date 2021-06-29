
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
// Don't add node class

class Solution {
    public Node flatten(Node head) {
        // Creating new pointer for traversal
        Node currentNode = head;
        while (currentNode != null) {
            if (currentNode.child != null) {
                // Pointer to find tail of the child liked list
                Node tail = currentNode.child;
                while (tail.next != null)
                    tail = tail.next;
                // Tail of child linked list
                tail.next = currentNode.next;
                if (currentNode.next != null) // Null pointer check
                    currentNode.next.prev = tail;
                currentNode.child.prev = currentNode;
                currentNode.next = currentNode.child;
                currentNode.child = null;
            }
            currentNode = currentNode.next;
        }
        return head;
    }
}
