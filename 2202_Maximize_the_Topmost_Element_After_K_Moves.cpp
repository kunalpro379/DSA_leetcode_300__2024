class Solution
{
public:
    int maximumTop(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k == 0)
            return nums[0];

        if (k == 1 && n == 1)
            return -1;

        if (k >= n) // return *max_element(nums.begin(), nums.end());
            return -1;
        // here if k is greater than the n then we can insert max element after poping all the elements from nums

        int max_val = -1;
        // find the max element of the first k-1 elements
        for (int i = 0; i < min(k - 1, n); i++)
            max_val = max(nums[i], max_val);

        if (k < n)
            max_val = max(max_val, nums[k]);

        return max_val;
    }
};