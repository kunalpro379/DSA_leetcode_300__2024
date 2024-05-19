class Solution {
public:
    int DFS(vector<vector<int>>&grid, int i, int j){
             int m=grid.size();
        int n=grid[0].size();
        if(i>=m||i<0||j>=n||j<0||grid[i][j]==0){
            return 0;
        }
        int originalGoldVal=grid[i][j];
        grid[i][j]=0;
        int maxGold=0;
        //UpDownLeftRight
int up = DFS(grid,i-1,j); // up
        int down = DFS(grid,i+1,j); // down
        int right = DFS(grid,i,j+1); // right
        int left = DFS(grid,i,j-1); // left
        int maxGoldFromCurrentPosition = max({up, down, right, left});

       grid[i][j]=originalGoldVal;
        return originalGoldVal + maxGoldFromCurrentPosition;


    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxGold=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    if(grid[i][j]!=0)
                        maxGold=max(maxGold, DFS(grid,i,j));
            }
        }return maxGold;
    }
};
