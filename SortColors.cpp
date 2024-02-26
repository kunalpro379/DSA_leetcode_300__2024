#include<iostream>
#include<vector>
using namespace std;
// class Solution {
// public:
//         int Partition(vector<int>& arr, int low, int high) {
//         int pivot = arr[high];
//         int i = low - 1;

//         for (int j = low; j < high; j++) {
//             if (arr[j] < pivot) {
//                 i++;
//                 swap(arr[i], arr[j]);
//             }
//         }

//         swap(arr[i + 1], arr[high]);
//         return i + 1;
//     }

//    void sortHelp(vector<int >&arr, int low , int high){
//         if(low<high){
//             int pivotInd=Partition(arr,low,high);
//             sortHelp(arr,low,pivotInd-1);
//                sortHelp(arr,pivotInd+1,high);
//         }

//     }

//     void sortColors(vector<int>& nums) {
//         int low,high;
//         sortHelp(nums,low,high);
//     }
// };
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1; 

        while (mid <= high) { 
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
