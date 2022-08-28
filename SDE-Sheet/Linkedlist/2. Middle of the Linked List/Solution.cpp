
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        // IF we have to return the first of the node when the numebr of nodes are even then even then:
        // while(fast->next != NULL && fast->next->next != NULL)
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
