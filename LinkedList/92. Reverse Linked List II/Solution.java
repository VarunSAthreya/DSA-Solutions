
//  Definition for singly-linked list.
//  public class ListNode {
//    int val;
//    ListNode next;
//    ListNode() {}
//    ListNode(int val) { this.val = val; }
//    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
//}

class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode currentNode = head;
        int currentPos = 1;
        ListNode start = head;

        while (currentPos < left) {
            start = currentNode;
            currentNode = currentNode.next;
            currentPos++;
        }

        ListNode tail = currentNode;
        ListNode newList = null;

        while (currentPos <= right) {
            ListNode next = currentNode.next;
            currentNode.next = newList;
            newList = currentNode;
            currentNode = next;
            currentPos++;
        }

        start.next = newList;
        tail.next = currentNode;

        return left > 1 ? head : newList;
    }
}

// start: It is taken to find the left -1 node, such that it can be used to
// attach the new reversed list.

// tail: It is initialized as left'th value of the list currently as after the
// reversal it would become the right'th of the list. So then it can be used to
// attach the remaining nodes of the list.

// conditional return: To check whether left > 1 to see if the whole list is to
// be reversed.
