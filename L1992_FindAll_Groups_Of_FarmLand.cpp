#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> res;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) { // If the current cell is farmland
                    int r1 = i, c1 = j, r2 = i, c2 = j;
                    findFarmlandHelper(land, r1, c1, r2, c2);
                    res.push_back({r1, c1, r2, c2});
                }
            }
        }
        
        return res;
    }
    
private:
    void findFarmlandHelper(vector<vector<int>>& land, int& r1, int& c1, int& r2, int& c2) {
        int m = land.size();
        int n = land[0].size();
        
        // Expand the group horizontally
        while (c2 + 1 < n && land[r1][c2 + 1] == 1) {
            ++c2;
        }
        
        // Expand the group vertically
        while (r2 + 1 < m && land[r2 + 1][c1] == 1) {
            ++r2;
        }
        
        // Mark the cells as visited
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                land[i][j] = 0;
            }
        }
    }
};
