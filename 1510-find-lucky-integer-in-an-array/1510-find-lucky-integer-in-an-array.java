class Solution {
    public int findLucky(int[] arr) {
        Map<Integer, Integer>freqMap=new HashMap<>();
        for(int num: arr){
            freqMap.put(num, freqMap.getOrDefault(num,0)+1);
        }
        //check for lucky integers
        int maxLucky=-1;
        for(Map.Entry<Integer, Integer> entry: freqMap.entrySet()){
            int key=entry.getKey();
            int freq=entry.getValue();
            if(key==freq)maxLucky=Math.max(maxLucky, key);
        }return maxLucky;
    }
}