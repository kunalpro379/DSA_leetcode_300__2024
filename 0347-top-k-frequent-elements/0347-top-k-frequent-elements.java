class Solution {
    public int[] topKFrequent(int[] nums, int k) {
                Map<Integer, Integer>freq=new HashMap<>();

        PriorityQueue<Integer>heap=new PriorityQueue<>(
            (a,b)->freq.get(a)-freq.get(b)
        );
        for(int num:nums){
            freq.put(num, freq.getOrDefault(num,0)+1);
            // else freq.get(num)++;
        }
        for(int num:freq.keySet()){
            heap.add(num);
            if(heap.size()>k)heap.poll();
        }
         List<Integer>res=new ArrayList<>();
        // int[] res={};
        // int i=0;
        while(!heap.isEmpty()){
            res.add(heap.poll());
            // res[i]=heap.poll();
            // i++;
            // heap.pop();
        }
        // Collections.reverse(res);
        // return res;
        int[] result = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            result[i] = res.get(i);
        }

        return result;
    }
}