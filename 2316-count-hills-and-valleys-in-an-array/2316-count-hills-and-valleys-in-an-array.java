class Solution {
    public int countHillValley(int[] nums) {
        int cnt=0;
        int prev=nums[0];
        for(int i=1;i<nums.length-1;i++){
            if(nums[i]==nums[i+1]) continue;
            if((nums[i]>prev&&nums[i]>nums[i+1])||(nums[i]<prev&&nums[i]<nums[i+1])){
                cnt++;
                prev=nums[i];
            }else{
                prev=nums[i];
            }
        }return cnt;
    }
}