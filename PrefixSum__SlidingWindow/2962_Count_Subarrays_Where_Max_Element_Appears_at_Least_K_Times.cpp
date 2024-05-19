class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxE=max(maxE,nums[i]);
        }
        long long total=0;
        int cnt=0,start=0,end=0;
        while(end<n){
            if(nums[end]==maxE)
                cnt++;
            while(cnt==k){
                total+=n-end;
                if(nums[start]==maxE)
                    cnt--;
                start++;
            }
            end++;
            
        }
        return total;
    }
};