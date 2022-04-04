
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        int count = 1;
        auto rep = head, last = head, start = head;
        while (rep)
        {
            if (count == k)
            {
                start = rep;
            }
            if (count > k)
            {
                last = last->next;
            }
            count++;
            rep = rep->next;
        }
        swap(last->val, start->val);
        return head;
    }
};
