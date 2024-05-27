class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        return Find(nums, 0, nums.size() - 1);
    }
    int Find(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = left + (right - left) / 2;

        int LeftMajority = Find(nums, left, mid);
        int rightMajority = Find(nums, mid + 1, right);
        // combining the results
        if (LeftMajority == rightMajority)
        {
            return LeftMajority;
        }
        else
        {
            int leftCount = countOcc(nums, LeftMajority, left, right);
            int rightCount = countOcc(nums, rightMajority, left, right);
            return leftCount > rightCount ? LeftMajority : rightMajority;
        }
    }
    int countOcc(std::vector<int> &nums, int target, int left, int right)
    {
        int count = 0;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] == target)
            {
                count++;
            }
        }
        return count;
    }
};