Node *mergeTwoLists(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if (a != NULL)
        temp->bottom = a;
    else
        temp->bottom = b;

    return res->bottom;
}

Node *flatten(Node *root) // main
{
    // base case for recursion
    if (root == NULL || root->next == NULL)
        return root;

    // flatten the lists on right
    root->next = flatten(root->next);

    // merge lists
    root = mergeTwoLists(root, root->next);
    // it will be in turn merged with its left
    return root;
}
