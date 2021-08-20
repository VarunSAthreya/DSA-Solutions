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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode *curr = head;
        int len = 1;
        while (curr->next != NULL)
        {
            len++;
            curr = curr->next;
        }

        k = k % len;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        curr = head;

        while (curr->next != NULL)
            curr = curr->next;

        curr->next = dummy->next;

        int index = len - k - 1;
        ListNode *newHead = head;

        while (index--)
            newHead = newHead->next;

        dummy->next = newHead->next;
        newHead->next = NULL;

        return dummy->next;
    }
};

// Compact Code

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        // edge cases
        if (!head || !head->next || k == 0)
            return head;

        // compute the length
        ListNode *cur = head;
        int len = 1;
        while (cur->next && ++len)
            cur = cur->next;

        // go till that node
        cur->next = head;
        k = k % len;
        k = len - k;
        while (k--)
            cur = cur->next;

        // make the node head and break connection
        head = cur->next;
        cur->next = NULL;

        return head;
    }
};
