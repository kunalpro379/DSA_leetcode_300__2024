class Solution {
public:

    int atleastK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n=nums.size();
        int start = 0;
        int end=0;
        int count = 0;
        int result = 0;

       while(end<n){
        freq[nums[end]]++;
        if(freq[nums[end]]==1)
            count++;
        //increase the window size till //number of differetn integers ==k
        while(count==k){
            result+=n-end;
            freq[nums[start]]--;
            if(freq[nums[start]]==0){count--;}
            start++;
        }
        end++;
       }return result;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atleastK(nums, k) - atleastK(nums, k + 1);
    }
};
