/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(!head) return NULL;
        //reversing 
        ListNode* prev=NULL;
        ListNode* current=head;

        while(current){
            ListNode* next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        ListNode* thisHead=prev;
        ListNode* temp=new ListNode(0);
        ListNode* tail=temp;
        int carry=0;
        //iterating from new head previous
        while(thisHead){
            int sum=(thisHead?thisHead->val:0)*2+carry;
            carry=sum/10;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            if(thisHead) thisHead=thisHead->next;
        }
        if(carry>0){
            tail->next=new ListNode(carry);
        }
        //reversing again
        ListNode* res=NULL;
        current=temp->next;
        while(current){
            ListNode* next=current->next;
            current->next=res;
            res=current;
            current=next;
        }
        delete temp;
        return res;


    }
};