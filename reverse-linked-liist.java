/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next==null) return head;

        ListNode prev=null;
        ListNode current=head;
        ListNode next=head.next;
        while(next!=null){
            current.next=prev;
            prev=current;
            current=next;
            next=next.next;
        }

        current.next=prev;
        return current;
        
    }
}
