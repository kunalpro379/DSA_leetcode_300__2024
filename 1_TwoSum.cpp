class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> numInd;
        for (int i = 0; i < nums.size(); i++)
        {
            numInd.push_back({nums[i], i});
        }
        sort(numInd.begin(), numInd.end());
        int left = 0;
        int right = numInd.size() - 1;
        while (left < right)
        {
            int sum = numInd[left].first + numInd[right].first;
            if (sum == target)
            {
                return {numInd[left].second, numInd[right].second};
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return {};
    }
};