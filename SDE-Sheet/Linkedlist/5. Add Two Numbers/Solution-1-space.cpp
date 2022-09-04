class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto node = l1;
        int c1 = 0, c2 = 0;
        while (node)
        {
            c1++;
            node = node->next;
        }
        node = l2;
        while (node)
        {
            c2++;
            node = node->next;
        }

        if (c2 > c1)
            swap(l1, l2);

        auto head = l1;
        int carry = 0;
        while (l1 || l2)
        {
            int val = l2 ? l2->val : 0;
            l1->val = l1->val + val + carry;
            if (l1->val > 9)
            {
                carry = l1->val / 10;
                l1->val = l1->val % 10;
            }
            else
                carry = 0;

            if (!l1->next && carry > 0)
            {
                node = new ListNode(carry);
                l1->next = node;
                break;
            }

            l1 = l1->next;

            if (l2)
                l2 = l2->next;
        }

        return head;
    }
};
