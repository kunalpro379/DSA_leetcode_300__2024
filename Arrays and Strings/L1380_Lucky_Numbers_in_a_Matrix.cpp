#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> luckyNumbers(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> res;

        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> minInRow(rows, INT_MAX);
        std::vector<int> maxInCol(cols, INT_MIN);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                minInRow[i] = min(minInRow[i], matrix[i][j]);
            }
        }
        for (int j = 0; j < cols; ++j)
        {
            for (int i = 0; i < rows; ++i)
            {
                maxInCol[j] = std::max(maxInCol[j], matrix[i][j]);
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == minInRow[i] && matrix[i][j] == maxInCol[j])
                    res.push_back(matrix[i][j]);
            }
        }

        return res;
    }
};
