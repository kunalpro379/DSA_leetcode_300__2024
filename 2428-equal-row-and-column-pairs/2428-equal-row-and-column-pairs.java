class Solution {
    public int equalPairs(int[][] grid) {
        int n=grid.length;
        Map<String, Integer>rowMap=new HashMap<>();
        for(int i=0;i<n;i++){
            StringBuilder sb=new StringBuilder();
            for(int j=0;j<n;j++)sb.append(grid[i][j]).append(',');
            String rowStr=sb.toString();
            rowMap.put(rowStr, rowMap.getOrDefault(rowStr,0)+1);

        }int cnt=0;
        for(int j=0;j<n;j++){
            StringBuilder sb =new StringBuilder();
            for(int i=0;i<n;i++)sb.append(grid[i][j]).append(",");
            String colStr=sb.toString();
            cnt+=rowMap.getOrDefault(colStr, 0);
        }return cnt;

    }
}