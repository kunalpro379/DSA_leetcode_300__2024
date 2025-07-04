class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> freqMap=new HashMap<>();
        int maxlen=0;
        for(int num:nums)freqMap.put(num,freqMap.getOrDefault(num,0)+1);
        //go thorugh each num 
        for(int key: freqMap.keySet()){
            if(freqMap.containsKey(key+1)){
                int len=freqMap.get(key)+freqMap.get(key+1);
                maxlen=Math.max(maxlen, len);
            }
        }return maxlen;
    }
}