class Solution
{
public:
    void dfs(int x, int y, vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
            return;
        board[x][y] = '#';
        dfs(x - 1, y, board); // Up
        dfs(x + 1, y, board); // Down
        dfs(x, y - 1, board); // Left
        dfs(x, y + 1, board); // Right
    }

    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        if (m == 0)
            return;
        int n = board[0].size();

        // dfs
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, board);     // Left boundary
            dfs(i, n - 1, board); // Right boundary
        }
        for (int j = 0; j < n; j++)
        {
            dfs(0, j, board);     // Top boundary
            dfs(m - 1, j, board); // Bottom boundary
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X'; //  'O' to 'X'
                }
                else if (board[i][j] == '#')
                {
                    board[i][j] = 'O'; // Revert
                }
            }
        }
    }
};
