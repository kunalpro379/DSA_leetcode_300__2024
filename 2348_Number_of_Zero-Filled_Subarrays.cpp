class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //APROACH !
       long long res=0;
       int n=nums.size();
       int i=0;
       while(i<n){
        long long l=0;
        if(nums[i]==0){
            while(i<n&& nums[i]==0){
                i++;
                l++;
            }
        }else
            i++;

        res+=(l)*(l+1)/2;
        }return res;

    //APPROACH 2
    }
};