/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {

        int length = 0;
        ListNode curr = head;
        while (curr != null) {
            length++;
            curr = curr.next;
        }
        int eachBucketNodes = length / k;
        int remainder = length % k;

        ListNode[] result = new ListNode[k];

        curr = head;
        ListNode prev = null;

        for (int i = 0; i < k; i++) {
            result[i] = curr;

            for (int count = 1; count <= eachBucketNodes + (remainder > 0 ? 1 : 0); count++) {
                prev = curr;
                curr = curr.next;
            }
            if (prev != null) {
                prev.next = null;
            }
            remainder--;

        }

        return result;

    }
}
