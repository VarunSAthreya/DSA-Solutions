/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
