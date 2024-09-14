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

    public ListNode MergeTwoLinkedList(ListNode l1, ListNode l2){
        if(l1==null)
        return l2;

        if(l2==null)
        return l1;

        if(l1.val < l2.val){
            l1.next = MergeTwoLinkedList(l1.next,l2);
            return l1;
        }else{
            l2.next = MergeTwoLinkedList(l1,l2.next);
            return l2;
        }
       
    }
    public ListNode partitionAndMergeLists(int start,int end,ListNode[] lists){
        if(start > end){
            return null;
        }
        if(start == end){
            return lists[start];
        }

        int mid = start + (end-start)/2;
        ListNode L1 = partitionAndMergeLists(start,mid,lists);
        ListNode L2 = partitionAndMergeLists(mid+1,end,lists);

        return MergeTwoLinkedList(L1,L2);
    }

    public ListNode mergeKLists(ListNode[] lists) {

        int k = lists.length;
        if(k==0){
            return null;
        }

        return partitionAndMergeLists(0,k-1,lists);
        
    }
}
