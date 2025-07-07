class Solution {
    public int numSubseq(int[] nums, int target) {
        int MOD = 1_000_000_007;
        Arrays.sort(nums);
        int n= nums.length;
        int[] powers=new int[n];
        powers[0]=1;
        for(int i=1;i<n;i++)powers[i]=(powers[i-1]*2)%MOD;
        int left=0, right=n-1, cnt=0;
        while(left<=right){
            if(nums[left] + nums[right] <= target){
                cnt=(cnt+powers[right-left])%MOD;
                left++;
            }
            else right--;
        }return cnt;
    }
}