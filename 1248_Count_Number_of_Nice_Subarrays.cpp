class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefix_sum_count;
        prefix_sum_count[0] = 1;
        int current_prefix_sum = 0;
        int nice_subarrays = 0;
        for (int num : nums)
        {
            current_prefix_sum += (num % 2);
            if (prefix_sum_count.find(current_prefix_sum - k) != prefix_sum_count.end())
            {
                nice_subarrays += prefix_sum_count[current_prefix_sum - k];
            }
            prefix_sum_count[current_prefix_sum]++;
        }
        return nice_subarrays;
    }
};