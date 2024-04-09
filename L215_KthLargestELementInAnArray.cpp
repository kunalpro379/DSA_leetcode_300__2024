class Solution {
    int partition(vector<int>&nums, int left, int right){
        int pivot=nums[right];
        int i=left-1;
        for(int j=left;j<right; j++){
            if(nums[j]>=pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1], nums[right]);
        return i+1;
    }

    int Selected(vector<int>&nums, int left, int right, int k){
        int pivotIndex=partition(nums,left,right);
        if(pivotIndex==k-1){
            return nums[pivotIndex];
        }
        else if(pivotIndex>k-1){return Selected(nums,left,pivotIndex-1, k);}
        else{
            return Selected(nums,pivotIndex+1,right, k);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return Selected(nums,0,size()-1,k);
    }
};