
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // Using node values
        node->val = node->next->val;
        node->next = node->next->next;
        // using pointers:
        *node = *node->next;
    }
};
