class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, vector<int>> digMap; // store the elements groupd by dig index i-j
        // traverse each ele in mat
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int digInd = i - j;
                digMap[digInd].push_back(mat[i][j]);
            }
        }
        // sort each dig
        for (auto &[index, dig] : digMap)
        {
            sort(dig.begin(), dig.end(), greater<int>());
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int digInd = i - j;
                mat[i][j] = digMap[digInd].back();
                digMap[digInd].pop_back();
            }
        }
        return mat;
    }
};