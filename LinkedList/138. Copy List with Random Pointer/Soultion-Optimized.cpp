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

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *node = head;
        Node *front = head;

        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while (node != NULL)
        {
            Node *front = node->next;
            node->next = new Node(node->val);
            node->next->next = front;
            node = front;
        }

        // Second round: assign random pointers for the copy nodes.
        node = head;
        while (node != NULL)
        {
            if (node->random != NULL)
                node->next->random = node->random->next;
            node = node->next->next;
        }

        // Third round: restore the original list, and extract the copy list.
        node = head;
        Node *dummy = new Node(0);
        Node *copy = dummy;

        while (node != NULL)
        {
            front = node->next->next;

            // extract the copy
            copy->next = node->next;

            // restore the original list
            node->next = front;

            copy = copy->next;
            node = front;
        }
        return dummy->next;
    }
};
