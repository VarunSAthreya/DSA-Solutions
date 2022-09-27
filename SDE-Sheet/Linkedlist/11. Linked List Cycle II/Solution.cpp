class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        do
        {
            if (fast == NULL || fast->next == NULL || fast->next->next == NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        fast = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
