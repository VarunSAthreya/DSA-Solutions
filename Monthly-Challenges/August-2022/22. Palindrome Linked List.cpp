class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head && !head->next)
            return true;

        auto slow = head;
        auto fast = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = revrse(slow->next);

        slow = slow->next;
        fast = head;

        while (slow)
        {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }

    ListNode *revrse(ListNode *node)
    {
        ListNode *pre = NULL;
        ListNode *next = NULL;

        while (node)
        {
            next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }

        return pre;
    }
};
