class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        // int n=grid.size();
        // vector<vector<int>>maxLocal(n-2,vector<int>(n-2,0));
        // for(int i=0;i<n-2;i++){
        //     for(int j=0;j<n-2;j++){
        //         int maxVal=grid[i][j];
        //         for(int k=i;k<3;k++){
        //             for(int m=j;m<3;m++){
        //                 maxVal=max(maxVal,grid[k][m]);
        //             }
        //         }maxLocal[i][j]=maxVal;
        //     }
        // }return maxLocal;
         int n=grid.size();
        vector<vector<int>>maxLocal(n-2,vector<int>(n-2,0));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                int maxVal=grid[i][j];
                for(int k=i-1;k<=i+1;k++){
                    for(int m=j-1;m<=j+1;m++){
                        maxVal=max(maxVal,grid[k][m]);
                    }
                }maxLocal[i-1][j-1]=maxVal;
            }
        }return maxLocal;
    }
};