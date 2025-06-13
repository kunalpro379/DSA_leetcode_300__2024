class Solution {
    public boolean increasingTriplet(int[] nums) {
        int first, second;
        first=second=Integer.MAX_VALUE;
        for(int num: nums){
            if(num<=first)first =num;
            else if(num<=second)second=num;
            else return true;
        }return false;
    }
}