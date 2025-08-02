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
    public int pairSum(ListNode head) {
        Stack<Integer>stk=new Stack<>();

        ListNode slow=head, fast=head;
        // slow=head;
        // fast=head.next;
        int twinSum = Integer.MIN_VALUE;
        // stk.push(slow.val);
        while(fast != null && fast.next != null){
            stk.push(slow.val);   
            slow=slow.next;
            fast=fast.next.next;
            // stk.push(slow.val);
        }
        while(slow!=null){
            int leftHalfVal = stk.pop();
            // stk.pop();
            // slow=slow.next;
            twinSum=Math.max(twinSum, slow.val+leftHalfVal);
            slow=slow.next;


        }return twinSum;

    }
}