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
    public void reorderList(ListNode head) {
        if(head==null||head.next  == null)return ;
        ListNode slow=head, fast=head;
while (fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;

        }
        ListNode secondHalf=REVERSE(slow.next);
        slow.next = null;         
        ListNode firstHalf=head;
        while(secondHalf!=null){
            // ListNode temp1=firstHalf.next;
            // ListNode temp2=secondHalf.next;
            // secondHalf = firstHalf.next;
            // secondHalf = temp1;

            // firstHalf=temp1;
            // temp1=temp1.next;
            // secondHalf=secondHalf.next;
            // temp2=temp2.next;
            ListNode temp1 = firstHalf.next;
            ListNode temp2 = secondHalf.next;

            firstHalf.next = secondHalf;
            secondHalf.next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }

    }
    private ListNode REVERSE(ListNode head) {
        ListNode prev = null, curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

}