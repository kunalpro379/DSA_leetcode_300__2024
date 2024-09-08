class Solution
{
public:
    int mostFrequent(vector<int> &nums, int key)
    {
        unordered_map<int, int> targetCount;
        int maxCount = 0;
        int res = -1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == key)
            {
                int target = nums[i + 1];
                targetCount[target]++;
                if (targetCount[target] > maxCount)
                {
                    maxCount = targetCount[target];
                    res = target;
                }
            }
        }
        return res;
    }
};