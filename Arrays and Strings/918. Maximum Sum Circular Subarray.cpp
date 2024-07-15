class Solution
{
public:
    int kadane(vector<int> &nums)
    {
        int max_sum = nums[0];
        int curr_sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            curr_sum = max(nums[i], curr_sum + nums[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        if (nums.empty())
            return 0;
        int maxKadane = kadane(nums);

        int total_sum = 0;
        for (int num : nums)
            total_sum += num; //

        for (int &num : nums)
            num = -num; // invering the sign of each element in the array

        int maxInvertedKadane = kadane(nums);
        // max circular sum
        int maxCircular = total_sum + maxInvertedKadane;

        if (maxCircular == 0)
            return maxKadane;
        else
            return max(maxKadane, maxCircular);
    }
};