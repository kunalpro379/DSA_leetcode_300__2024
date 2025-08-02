class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length<=1)return intervals;
        List<int[]>result=new ArrayList<>();
        Arrays.sort(intervals,(a,b)->Integer.compare(a[0],b[0]));
        // currMax=intervals[0][1];
        // currMin=inervals[1][0];
        int[] curr=intervals[0];
        result.add(curr);
        for(int[] interval: intervals){
                int currstart=curr[0];
                int currend=curr[1];
                int nextstart=interval[0];
                int nextend=interval[1];
                if(nextstart<=currend)curr[1]=Math.max(nextend, currend);
                else{
                    curr=interval;
                    result.add(curr);
                }
        }return result.toArray(new int[result.size()][]);
    }
}