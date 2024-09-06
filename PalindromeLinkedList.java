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

    ListNode findMid(ListNode head){

        if(head.next == null){
            return head;
        }
        ListNode slow = head;
        ListNode fast = head;

        while(fast!=null && fast.next!=null){
            fast = fast.next.next;
            slow=slow.next;
        }
        return slow;

    }

    ListNode reverse(ListNode head){
       ListNode curr = head;
       ListNode prev = null;
       ListNode forw = null;

        while(curr!=null){
            forw = curr.next;
            curr.next =  prev;
            prev = curr;
            curr= forw;
        }
        return prev;
    }

    public boolean isPalindrome(ListNode head) {

        ListNode mid = findMid(head);
        ListNode slow = reverse(mid);

        while(slow!=null && (slow.val == head.val)){
            head = head.next;
            slow = slow.next;
        }

        return slow == null;
    }
}
