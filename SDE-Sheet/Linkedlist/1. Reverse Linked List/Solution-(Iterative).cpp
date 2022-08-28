class Solution
{
public:
    ListNode *reverseNode(ListNode *head)
    {
        ListNode *newHead = nullptr;
        ListNode *next = nullptr;

        while (head)
        {
            next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }

        return newHead;
    }
}
