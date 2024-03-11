#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 Definition for singly-linked list.
 struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < n; ++i){
            if (fast == NULL) {//
                return head;//
            }//
            fast = fast->next;
    }

            while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        if(fast == NULL) {
                    ListNode* newHead = head->next;
             delete head;
            return newHead;
        }

        ListNode* deletN = slow->next;
            slow->next = slow->next->next;
            delete deletN;

        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* newHead = sol.removeNthFromEnd(head, 2);

    while(newHead != NULL){
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}