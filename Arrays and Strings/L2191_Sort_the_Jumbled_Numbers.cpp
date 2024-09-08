#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    // Convert a number to its mapped value as an integer
    int mapVal(const vector<int> &mapping, int num)
    {
        string numStr = to_string(num);
        string mapStr = "";
        for (char ch : numStr)
        {
            int digit = ch - '0';
            mapStr += to_string(mapping[digit]);
        }
        // Convert the mapped string to integer and return
        return stoi(mapStr);
    }

    // Comparator function to sort based on mapped integer values
    static bool compare(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second < b.second;
    }

    vector<int> sortJumbled(const vector<int> &mapping, const vector<int> &nums)
    {
        vector<pair<int, int>> mappedNums;

        for (int num : nums)
        {
            int mappedValue = mapVal(mapping, num);
            mappedNums.push_back({num, mappedValue});
        }

        // Sort based on the mapped integer values
        sort(mappedNums.begin(), mappedNums.end(), compare);

        vector<int> sortedNums;
        for (const auto &p : mappedNums)
        {
            sortedNums.push_back(p.first);
        }

        return sortedNums;
    }
};
