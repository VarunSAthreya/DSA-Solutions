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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        vector<int> vec;
        ListNode *node = head;
        while (node != NULL)
        {
            vec.push_back(node->val);
            node = node->next;
        }
        int left = 0, right = vec.size() - 1;

        while (left < right)
        {
            if (vec[left] != vec[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
