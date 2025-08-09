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
            // BiFunction<Integer, Integer, Integer>DP=new BiFunction<>(){
            //     public Integer apply(Integer m, Integer n){
            //         if()
            //         if()
            //         if()
            //         if()
            //         return
            //     }
            // }
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
        return Memorization.apply(word1.length(), word2.length());
        // return DP.apply();
        // return SpaceOpt.apply();
    }
}
