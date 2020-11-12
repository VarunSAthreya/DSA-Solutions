public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        
        while(slow != fast) {
            if (slow.next == null || fast.next == null || fast.next.next == null) {
                return null;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        fast = fast.next;
        int length = 1;
        while(slow != fast) {
            length += 1;
            fast = fast.next;
        }
        slow = head;
        fast = head;
        for (int i = 0; i < length; i++) {
            fast = fast.next;
        }
        
        while(slow != fast) {
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }
}