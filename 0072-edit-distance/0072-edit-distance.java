class Solution {
    public int minDistance(String word1, String word2) {
        BiFunction<Integer, Integer, Integer> Recursion  =
            new BiFunction<>() {
                public Integer apply(Integer m, Integer n) {
                    if (m == 0) return n;
                    if (n == 0) return m;

                    if (word1.charAt(m - 1) == word2.charAt(n - 1)) {
                        return this.apply(m - 1, n - 1);
                    }

                    return 1 + Math.min(
                        this.apply(m - 1, n), // delete
                        Math.min(
                            this.apply(m, n - 1), // insert
                            this.apply(m - 1, n - 1) // replace
                        )
                    );
                }
            };
            BiFunction<Integer, Integer, Integer>Memorization=new BiFunction<>(){
                int[][] DP=new int[word1.length()+1][word2.length()+1];{
                    for (int[] row : DP)Arrays.fill(row, -1);

                }

                public Integer apply(Integer m , Integer n){
                    if(m==0)return n;
                    if(n==0)return m;
                    if(DP[m][n]!=-1)return DP[m][n];
                    if(word1.charAt(m-1)==word2.charAt(n-1))return DP[m][n]=this.apply(m-1, n-1);
                    return DP[m][n]=1+Math.min(
                        this.apply(m-1, n),//delete
                        Math.min(
                            this.apply(m, n-1),//Insert
                            this.apply(m-1, n-1)//replace
                        )
                    );
                }
            };
            BiFunction<Integer, Integer, Integer>DP=new BiFunction<>(){
                public Integer apply(Integer m, Integer n){
                    int[][] Tab=new int[m+1][n+1];{
                    for(int i=0;i<=m;i++)Tab[i][0]=i;
                    for(int j=0;j<=n;j++)Tab[0][j]=j;
                    }
                    for(int i=1;i<=m;i++){
                        for(int j=1;j<=n;j++){
                            if(word1.charAt(i-1)==word2.charAt(j-1))Tab[i][j]=Tab[i-1][j-1];
                            else Tab[i][j]=1+Math.min(Tab[i-1][j], Math.min(Tab[i][j-1], Tab[i-1][j-1]));
                        }
                    }
                    return Tab[m][n];
                }
            };
            // BiFunction<Integer, Integer, Integer>SPaceOpt=new BiFunction<>(){
            //     public Integer apply(Integer m, Integer n){
            //         if()
            //         if()
            //         if()
            //         if()
            //         return
            //     }
            // }

        // return Recursion.apply(word1.length(), word2.length());
        // return Memorization.apply(word1.length(), word2.length());
        return DP.apply(word1.length(), word2.length());
        // return SpaceOpt.apply(word1.length(), word2.length());
    }
}
