class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mapp;
        mapp[NULL] = NULL;

        Node *node = head;

        while (node != NULL)
        {
            Node *temp = new Node(node->val);
            mapp[node] = temp;
            node = node->next;
        }

        node = head;

        while (node != NULL)
        {
            mapp[node]->next = mapp[node->next];
            mapp[node]->random = mapp[node->random];
            node = node->next;
        }

        return mapp[head];
    }
};
