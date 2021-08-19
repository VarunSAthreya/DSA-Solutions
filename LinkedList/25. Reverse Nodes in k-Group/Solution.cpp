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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || k == 1)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head; // to indicate new head after reverse
        ListNode *curr = dummy, *pre = dummy, *nex = dummy;
        int len = 0; // count the length of the linked list
        while (curr->next != NULL)
        {
            curr = curr->next;
            len++;
        }

        while (len >= k) // to leave the last remaining lengths which are less than k
        {
            curr = pre->next;
            nex = curr->next;

            // Runs k-1 times to revese the ll
            for (int i = 1; i < k; i++)
            {
                // Reverse logic
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            len -= k;
        }
        // returns new head
        return dummy->next;
    }
};
