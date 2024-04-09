// class KthLargest {
// public:
// int k;
// priority_queue<int,vector<int>, greater<int>>minHeap;
//     KthLargest(int k, vector<int>& nums) {
//         this->k=k;
//         for(int num: nums){add(num);}
//     }
    
//     int add(int val) {
//         if(minHeap.size()<k){
//             minHeap.push(val);
//         }
//         else if(val>minHeap.size()){
// minHeap.pop();
// minHeap.push(val);
//         }
//         return minHeap.top();
//     }
// };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to store the k largest elements

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num); 
        }
    }

    int add(int val) {
        pq.push(val); 
        if (pq.size() > k) {
            pq.pop(); 
        }
        return pq.top(); 
    }
};
