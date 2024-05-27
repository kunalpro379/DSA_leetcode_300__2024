class Solution
{
public:
    // reccuressive solution//////////////////
    //  int dfs(vector<vector<int>>& matrix, int i, int j){
    //      vector<pair<int, int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
    //      int res=1;
    //      for(const auto& dir:dirs){
    //          int x=i+dir.first;
    //          int y=j+dir.second;
    //          if(x>=0&& x<matrix.size()&&y>=0&&y<matrix[0].size()&&matrix[x][y]>matrix[i][j]){
    //              res=max(res,1+dfs(matrix,x,y));
    //          }
    //      }
    //      return res;
    //  }
    //  int longestIncreasingPath(vector<vector<int>>& matrix) {
    //      if(matrix.empty())return 0;
    //      int m=matrix.size();
    //      int n=matrix[0].size();
    //      int maxL=0;
    //      for(int i=0;i<m;i++){
    //          for(int j=0;j<n;j++){
    //                  maxL=max(maxL,dfs(matrix,i, j));
    //          }
    //      }
    //      return maxL;
    //  }

    // memorizationn///////////////////////
    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &memo)
    {
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        if (memo[i][j] != 0)
            return memo[i][j];

        int res = 1;
        for (const auto &dir : dirs)
        {
            int x = i + dir.first;
            int y = j + dir.second;
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j])
            {
                res = max(res, 1 + dfs(matrix, x, y, memo));
            }
        }
        memo[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, 0));
        if (matrix.empty())
            return 0;

        int maxL = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxL = max(maxL, dfs(matrix, i, j, memo));
            }
        }
        return maxL;
    }
};