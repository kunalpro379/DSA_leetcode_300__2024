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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // ListNode dummy=new ListNode(-1);//dummy head
        if (list1 == null) return list2;
        if (list2 == null) return list1;
        ListNode head;

        // ListNode node1=list1;
        // ListNode node2=list2;

        // while(list1!=null&& list2!=null){
        if(list1.val<=list2.val){
                head=list1;
                list1=list1.next;
        }else{
                head=list2;
                list2=list2.next;
            }
        ListNode current=head;
        while(list1!=null&& list2!=null){
            if(list1.val<=list2.val){
                current.next=list1;
                list1=list1.next;
            }else{
                current.next=list2;
                list2=list2.next;
            }
            current=current.next;
        }
        if(list1!=null)current.next=list1;
        else current.next=list2;
        return head;
    }
}