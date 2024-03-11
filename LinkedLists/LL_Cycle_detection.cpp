#include<iostream>
using namespace std;    
#include<unordered_map>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {

    unordered_map<ListNode*, bool >HashNextPtr;
public:

// void BuildHash(ListNode* head){
//     ListNode* current =head;
//     while(current!=NULL){
//         HashNextPtr[current->val]={current, current ->next};
//         current =current ->next;
//     }
// }
    bool hasCycle(ListNode *head) {
        ListNode* current =head;
        while(current !=NULL){
            if(HashNextPtr.find(current)!=HashNextPtr.end()){
                return true;
            }
             HashNextPtr[current]=true;
        current =current ->next;
        }
        return false;
    }
};
