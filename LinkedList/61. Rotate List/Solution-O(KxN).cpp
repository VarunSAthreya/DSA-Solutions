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
        int count = 1;
        while (curr->next != NULL)
        {
            count++;
            curr = curr->next;
        }

        k = k % count;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        while (k--)
        {
            curr = dummy->next;
            while (curr->next->next != NULL)
            {
                curr = curr->next;
            }

            curr->next->next = dummy->next;
            dummy->next = curr->next;
            curr->next = NULL;
        }
        return dummy->next;
    }
};
