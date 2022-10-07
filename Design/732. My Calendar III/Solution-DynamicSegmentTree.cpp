class MyCalendarThree
{
private:
    class Node
    {
    public:
        int start, end, maxi, lazy;
        Node *left, *right;
        Node(int st, int ed)
        {
            start = st;
            end = ed;
            left = NULL, right = NULL;
            lazy = 0, maxi = 0;
        }
    };

    class SegmentTree
    {
    public:
        Node *root;
        SegmentTree(int n)
        {
            root = new Node(0, n);
        }

        void update(int L, int R, Node *curr)
        {
            if (L <= curr->start && R >= curr->end)
            {
                curr->lazy += 1;
            }

            push(curr);

            if (L <= curr->start && R >= curr->end || L > curr->end || R < curr->start)
                return;

            update(L, R, curr->left);
            update(L, R, curr->right);

            curr->maxi = max(curr->left->maxi, curr->right->maxi);
        }

        void push(Node *curr)
        {
            curr->maxi += curr->lazy;

            if (curr->start != curr->end)
            {
                int mid = curr->start + (curr->end - curr->start) / 2;
                if (curr->left == NULL)
                {
                    curr->left = new Node(curr->start, mid);
                }

                if (curr->right == NULL)
                {
                    curr->right = new Node(mid + 1, curr->end);
                }

                curr->left->lazy += curr->lazy;
                curr->right->lazy += curr->lazy;
            }

            curr->lazy = 0;
        }
    };

    SegmentTree *st = new SegmentTree(1e9);
    Node *root = st->root;

public:
    MyCalendarThree() {}

    int book(int start, int end)
    {
        st->update(start, end - 1, root);
        return root->maxi;
    }
};
