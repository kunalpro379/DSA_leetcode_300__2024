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
     ListNode* merge(ListNode* left, ListNode* right){
       if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        ListNode* res=NULL;
        if(left->val<right->val){
            res=left;
            res->next=merge(left->next, right);
            return left;
        }else{
            right->next=merge(left, right->next);
            return right;
        }
     }
    ListNode* getMiddle(ListNode* head){
        if(head==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast =head->next;

        while(fast!=NULL&& fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        //spliting two halves
        ListNode* middle=getMiddle(head);
        ListNode* nextToMiddle=middle->next;
        middle->next=NULL;

        //sorting two halves reccuresively
        ListNode* left =sortList(head);
        ListNode* right =sortList(nextToMiddle);

        return merge(left,right );


    }


    //using reccurssion
    //  ListNode* sortList(ListNode* head) {



    //  }

};