class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = 0;
        auto node = head;
        while (node)
        {
            len++;
            node = node->next;
        }

        if (len == 1)
            return NULL;

        int ind = len - n;
        if (ind == 0)
            return head->next;

        node = head;
        while (--ind)
            node = node->next;

        node->next = node->next->next;

        return head;
    }
};

// DIFFERENT IMPLEMENTATION
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = 1;
        ListNode *last = head;
        while (last->next != NULL)
        {
            len++;
            last = last->next;
        }
        len = len - n;
        last = head;
        if (len == 0)
        {
            head = head->next;
            return head;
        }
        int count = 1;
        while (count < len)
        {
            count++;
            last = last->next;
        }
        if (last != NULL && last->next != NULL)
        {
            last->next = last->next->next;
        }
        return head;
    }
};
