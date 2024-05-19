class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m =grid.size();
        int n=grid[0].size();
        //ensuring leftmost digit of each row is 1
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){//if leftmost digit is 0,flip
                for(int j=0;j<n;j++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        for(int j=1;j<n;j++){
            int countOnes=0;
            for(int i=0;i<m;i++){
                countOnes+=grid[i][j];
            }
            if(countOnes<m-countOnes){
                for(int i=0;i<m;i++){
                   grid[i][j] = 1 - grid[i][j];

                }
            }
        }
        int score=0;
        for(int i=0;i<m;i++){
            int rowVal=0;
            for(int j=0;j<n;j++){
                rowVal=(rowVal<<1)+grid[i][j];
            }score+=rowVal;
        }return score;

    }
};