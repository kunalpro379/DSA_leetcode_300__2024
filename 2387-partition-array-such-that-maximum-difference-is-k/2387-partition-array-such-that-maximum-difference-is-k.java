class Solution {
    public int partitionArray(int[] nums, int k) {
        //sort the array'
        Arrays.sort(nums);
        int cnt=1;
        int minVal=nums[0];
        for(int i=0;i< nums.length;i++){
            if(nums[i]-minVal>k){
                cnt++;
                minVal=nums[i];
            }
        }return cnt;

    }
}