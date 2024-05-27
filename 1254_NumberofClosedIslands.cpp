// class Solution {
// public:

// bool isValid(vector<vector<int>>&grid, int i, int j){
//         return i>=0&&i<grid.size()&&j>=0&& j<grid[0].size();
//     }
//  void dfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>&visited){
//     if(!isValid(grid,i,j) || grid[i][j] == 1||visited[i][j])
//         return;
//     //grid[i][j] = 1;
//     visited[i][j]=true;
//     dfs(grid,i+1,j,visited); dfs(grid,i-1,j,visited); dfs(grid,i,j+1,visited); dfs(grid,i,j-1,visited);
// }

//     int closedIsland(vector<vector<int>>& grid) {
//         vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
//         if(grid.empty()) return 0;

//         int closeland=0;
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[0].size();j++){
//                 if(grid[i][j]==0&&!visited[i][j]){//lund
//                 if(i == 0||i==grid.size()-1||j == 0 ||j == grid[0].size()-1){
//                     dfs(grid,i,j,visited);
//                 }
//                 else{
//                     dfs(grid,i,j,visited);
//                     closeland++;
//                 }
//                 }
//             }
//         }return closeland;
//     }
// };
class Solution
{
public:
    bool isValid(int i, int j, int m, int n)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        int closedLand = 0;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    bool isClosed = true;
                    queue<pair<int, int>> q;
                    q.push({i, j}); //
                    grid[i][j] = 1; //

                    while (!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto &dir : directions)
                        {
                            int newX = x + dir.first;
                            int newY = y + dir.second;

                            if (isValid(newX, newY, m, n))
                            {
                                if (grid[newX][newY] == 0)
                                {
                                    q.push({newX, newY});
                                    grid[newX][newY] = 1; // Mark the neighbor as visited
                                }
                            }
                            else
                            {
                                isClosed = false;
                            }
                        }
                    }

                    if (isClosed)
                    {
                        ++closedLand;
                    }
                }
            }
        }

        return closedLand;
    }
};
