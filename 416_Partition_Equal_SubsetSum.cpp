class Solution
{
public:
    bool fn(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return (arr[0] == target);
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool not_take = fn(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
            take = fn(ind - 1, target - arr[ind], arr, dp);
        return dp[ind][target] = take || not_take;
    }
    bool canPartition(vector<int> &nums)
    {
        int total_sum = 0;
        for (int i = 0; i < nums.size(); i++)
            total_sum += nums[i];
        if (total_sum % 2 != 0)
            return false;
        // return true;
        int target = total_sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return fn(nums.size() - 1, target, nums, dp);
    }
};