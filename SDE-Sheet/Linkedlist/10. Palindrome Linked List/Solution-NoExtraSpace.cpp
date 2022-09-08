
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;

        fast = head;
        while (slow != NULL)
        {
            if (slow->val != fast->val)
                return false;

            slow = slow->next;
            fast = fast->next;
        }

        // TODO: IF THE INTERVIEWER ASKS TO RETURN BACK THE ORIGINAL LIST:

        // slow = head;
        // fast = head;
        // while (fast->next != NULL && fast->next->next != NULL)
        // {
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // slow->next = reverse(slow->next);

        return true;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while (head != NULL)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
