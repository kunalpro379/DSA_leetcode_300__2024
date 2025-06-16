// class Solution {

//     public int rob(int[] nums) {
//         IntFunction<Integer>helper=new IntFunction<>(){//Functional Interface

//             @Override
//             public Integer apply(int i){
//                 if(i>=nums.length)return 0;
//                 //two options skip or rob
//                 //max of two options
//                 return Math.max(nums[i]+this.apply(i+2), this.apply(i+1));
//             }
//         };
//         return helper.apply(0);//start from first hotel
//     }
// }

class Solution {
    public int rob(int[] nums) {
        int rob=0; 
        int notrob=0;
        for(int num: nums){
            int newrob=notrob+num;
            int newnotrob=Math.max(rob, notrob);
            rob=newrob;
            notrob=newnotrob;
        }return Math.max(rob, notrob);

    }
}