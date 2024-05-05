class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Directions: up, down, left, right

        // Traversing the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) { // If current cell is land
                    queue<pair<int, int>> Q;
                    Q.push({i, j});
                    grid[i][j] = -1; // Mark cell as visited

                    while (!Q.empty()) {
                        auto [x, y] = Q.front();
                        Q.pop();

                        // Explore neighbors
                        for (const auto& dir : dirs) {
                            int nx = x + dir[0];
                            int ny = y + dir[1];
                            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || grid[nx][ny] == 0) {
                                peri++;
                            } else {
                                Q.push({nx, ny});
                                grid[nx][ny] = -1; // Mark neighbor cell as visited
                            }
                        }
                    }
                }
            }
        }
        return peri;
    }
};
