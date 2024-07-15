class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        auto rev = [](vector<int> &arr, int start, int end)
        {
            while (start < end)
            {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
        };
        rev(nums, 0, n - 1); // rev entire arr
        rev(nums, 0, k - 1); // rev first k elements
        rev(nums, k, n - 1); // rev remaining n-k elements
    }
};