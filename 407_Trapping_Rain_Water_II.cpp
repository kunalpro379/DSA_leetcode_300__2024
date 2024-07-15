class Solution
{
public:
    bool IsBoundary(int i, int j, int m, int n)
    {
        return i > 0 && i < m - 1 && j > 0 && j < n - 1;
    }

    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();
        if (m == 0)
            return 0;
        int n = heightMap[0].size();
        if (n == 0)
            return 0;
        vector<vector<int>> container(m, vector<int>(n, 0));
        int totalWater = 0;
        int maxElement = 9999999;

        for (const auto &row : heightMap)
        {
            for (int val : row)
            {
                if (val > maxElement)
                {
                    maxElement = val;
                }
            }
        }
        cout << maxElement;

        for (int layer = 1; layer <= maxElement; ++layer)
        {

            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (heightMap[i][j] >= 1)
                    {
                        container[i][j] += 1;
                    }
                    if (container[i][j] == layer - 1 && IsBoundary(i, j, m, n))
                        totalWater += 1;
                }
            }
        }

        return totalWater;
    }
};

/*
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        int totalpani = 0;

        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int minHeight = 99999999;

                // Check top, bottom, left, right neighbors
                if (heightMap[i - 1][j] > heightMap[i][j] && heightMap[i + 1][j] > heightMap[i][j] &&
                    heightMap[i][j - 1] > heightMap[i][j] && heightMap[i][j + 1] > heightMap[i][j]) {

                    minHeight = min(minHeight, heightMap[i - 1][j]);
                    minHeight = min(minHeight, heightMap[i + 1][j]);
                    minHeight = min(minHeight, heightMap[i][j - 1]);
                    minHeight = min(minHeight, heightMap[i][j + 1]);
                }

                int waterTrappedAbove = max(0, minHeight - heightMap[i][j]);
                totalpani += waterTrappedAbove;
                heightMap[i][j] += waterTrappedAbove;
            }
        }

        return totalpani;
    }
};


*/