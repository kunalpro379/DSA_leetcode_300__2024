class Solution {
    public boolean canPair(int[] nums, int p, int maxDiff){
        int pairs=0;
        int i=0;
        while(i< nums.length-1){
            if(Math.abs(nums[i+1]-nums[i])<=maxDiff){
                pairs++;
                i+=2;
            }else i++;
            if(pairs>=p)return true;
        }
        return pairs>=p;
    }
    public int minimizeMax(int[] nums, int p) {
        //sort the array first 
        Arrays.sort(nums);
        if(p==0)return 0;
        int left=0;
        int right=nums[nums.length-1]-nums[0];//largest possible difference
        while(left<right){
            int mid=left+(right-left)/2;
            if(canPair(nums,p, mid))right=mid;
            else left=mid+1;
        }return left;
    }
}