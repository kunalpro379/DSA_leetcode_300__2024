class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        int totalOnes = 0;
        for (int num : nums)
        {
            if (num == 1)
            {
                totalOnes++;
            }
        }
        int maxOnesInWindow = 0;
        int currentOnesInWindow = 0;

        for (int i = 0; i < totalOnes; i++)
            if (nums[i] == 1)
                currentOnesInWindow++;
        maxOnesInWindow = currentOnesInWindow;

        // slide the window
        for (int i = totalOnes; i < n + totalOnes; i++)
        {
            // add the next ele in the window circular arr
            if (nums[i % n] == 1)
                currentOnesInWindow++;
            if (nums[(i - totalOnes) % n] == 1)
                currentOnesInWindow--; // removing an element
            maxOnesInWindow = max(maxOnesInWindow, currentOnesInWindow);
        }
        return totalOnes - maxOnesInWindow;
    }
};