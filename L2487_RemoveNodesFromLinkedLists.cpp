
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
    ListNode* removeNodes(ListNode* head) {

        if(head==NULL) return NULL;
        //Reversing a Linked List 
        ListNode* prev=NULL;
        ListNode* current=head;
        ListNode* next;
        while(current!=NULL){
            next=current->next;
            current ->next =prev;
            prev=current;
            current=next;
        }
        ListNode* revHead=prev;

        ListNode* res=NULL;
        ListNode* resTail=NULL;
        int maxVal=INT_MIN;
        current =revHead;
        while(current!=NULL){
            if(current->val>=maxVal){
                maxVal=current->val;
                if(res==NULL){
                    res=new ListNode(current->val);
                    resTail=res;
                }else{
                    resTail->next=new ListNode(current->val);
                    resTail=resTail->next;
                }
            }current=current->next;


        }
        prev=NULL;
        current=res;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
};
```