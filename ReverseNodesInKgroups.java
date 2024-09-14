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
    void reverse(ListNode start,ListNode end){
        ListNode current = start;
        ListNode next = current.next;
        ListNode previous = null;

        while(previous!=end){
            current.next = previous;
            previous = current;
            current = next;
            if(next!=null) next=next.next;
        }

    }
    public ListNode reverseKGroup(ListNode head, int k) {

        if(head == null || head.next == null || k==1){
            return head;
        }

        ListNode s = head;
        ListNode e = head;
        int inc = k-1;
        while(inc!=0){
            e=e.next;
            if(e==null) return head;
            inc--;
        }

        ListNode nexthead = reverseKGroup(e.next,k);
        reverse(s,e);
        s.next = nexthead;
        return e;
        
    }
}
