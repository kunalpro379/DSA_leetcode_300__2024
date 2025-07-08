class Solution {
    private int bruteforce(int[][] events, int k){
        Arrays.sort(events, (a,b)->a[0]-b[0]);
        //sorted by start dat
        int n=events.length;
        return dfs(0,k,0,events);
    }
    private int memorization(int[][] events, int k){
        Arrays.sort(events, (a,b)->a[0]-b[0]);
        int n=events.length;
        Integer[][] memo=new Integer[n][k+1];
        // Map<String, Integer>memo=new HashMap<>();
        return MemoApproach(0,k,events,memo);

    }
    private int dfs(int index, int k, int lastEnd, int[][] events){
        if(index==events.length||k==0)return 0;
        //skip current event
        int skip=dfs(index+1, k,lastEnd, events);
        //take current event only if doesnt overlap
        int take=0;
        if(events[index][0]>lastEnd)take=events[index][2]+dfs(index+1, k-1, events[index][1], events);
        return Math.max(skip, take);
    }
        private int dfsmemo(int index, int k, int lastEnd, int[][] events,  Map<String, Integer> memo){
        if(index==events.length||k==0)return 0;
        // if(memo[index][k]!=null)return memo[index][k];
        String key = index + "#" + k + "#" + lastEnd;
        if(memo.containsKey(key))return memo.get(key);
        //skip current event
        int skip=dfsmemo(index+1, k,lastEnd, events,memo);
        //take current event only if doesnt overlap
        int take=0;
        if(events[index][0]>lastEnd)take=events[index][2]+dfsmemo(index+1, k-1, events[index][1], events, memo);
        // memo[index][k]=Math.max(skip, take);
        memo.put(key, Math.max(skip, take));
        // return memo[index][k];
         return memo.get(key);
    }
            private int MemoApproach(int index, int k,int[][] events, Integer[][] memo){
        if(index==events.length||k==0)return 0;
        if(memo[index][k]!=null)return memo[index][k];
        //skip current event
        int skip=MemoApproach(index+1, k, events,memo);
        //take current event only if doesnt overlap
        int nextIndex=findNext(events, index);
        int take=0;
        take=events[index][2]+MemoApproach(nextIndex, k-1,  events, memo);
        memo[index][k]=Math.max(skip, take);
        return memo[index][k];
    }
    private int findNext(int[][] events, int currIndex){
        int low =currIndex+1, high=events.length;
        int target=events[currIndex][1];
        while(low<high){
            int mid = (low + high) / 2;

            if(events[mid][0]>target)high=mid;
            else low=mid+1;
        }return low;
    }
    public int maxValue(int[][] events, int k) {
        return memorization(events, k);
    }
}