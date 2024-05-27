class Solution
{
public:
    bool dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y, int px, int py, char startChar)
    {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited[x][y] = true;
        for (auto dir : directions)
        {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size())
            {
                if (nx == px && ny == py)
                    continue;
                if (grid[nx][ny] == startChar)
                {
                    if (visited[nx][ny])
                        return true;
                    if (dfs(grid, visited, nx, ny, x, y, startChar))
                        return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // traversing each cell
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j]))
                        return true;
            }
        }
        return false;
    }
};