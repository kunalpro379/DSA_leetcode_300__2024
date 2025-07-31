class Solution {
    public int findKthLargest(int[] nums, int k) {
        // Arrays.sort(nums);
        // return nums[nums.length-k];
        PriorityQueue<Integer>minHeap=new PriorityQueue<Integer>(k);
        for(int num:nums){
            minHeap.add(num);
            if(minHeap.size()>k)minHeap.poll();
        }
        return minHeap.peek();
    }
}