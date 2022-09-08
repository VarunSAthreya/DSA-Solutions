class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<ListNode *> st;
        auto node = head;

        while (node)
        {
            st.push(node);
            node = node->next;
        }

        node = head;
        while (!st.empty())
        {
            auto tmp = st.top();
            st.pop();

            if (tmp->val != node->val)
                return false;

            node = node->next;
        }

        return true;
    }
};
