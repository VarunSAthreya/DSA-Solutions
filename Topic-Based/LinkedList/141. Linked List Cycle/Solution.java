// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}
// Don't add ListNode class

// O(n) space solution can be done by using hashmap or set.

// Solved using Floyd's (Tortoise and Hare) Algorithm.

public class Solution {

    public boolean hasCycle(ListNode head) {
        if (head == null)
            return false;

        ListNode slow = head;
        ListNode fast = head;
        // Loop to find weather there is a cycle.
        do {
            if (fast.next != null && fast.next.next != null) {
                slow = slow.next;
                fast = fast.next.next;
            } else {
                return false;
            }
        } while (fast != slow);
        return true;
    }
}
