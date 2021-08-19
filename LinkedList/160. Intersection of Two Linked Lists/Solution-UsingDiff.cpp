/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA;
        ListNode *b = headB;
        int countA = 1;
        int countB = 1;
        while (a->next != NULL || b->next != NULL)
        {
            if (a->next != NULL)
            {
                countA++;
                a = a->next;
            }
            if (b->next != NULL)
            {
                countB++;
                b = b->next;
            }
        }
        a = headA;
        b = headB;
        if (countA > countB)
        {
            int diff = countA - countB;
            while (diff--)
            {
                a = a->next;
            }
        }
        if (countA < countB)
        {
            int diff = countB - countA;
            while (diff--)
            {
                b = b->next;
            }
        }
        while (a != NULL && b != NULL)
        {
            if (a == b)
            {
                return a;
            }
            a = a->next;
            b = b->next;
        }
        return NULL;
    }
};
