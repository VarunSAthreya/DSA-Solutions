class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
            return NULL;

        auto slow = head, fast = head->next->next;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return head;
    }
};
