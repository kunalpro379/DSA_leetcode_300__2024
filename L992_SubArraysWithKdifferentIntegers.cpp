class Solution {
public:

    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int count = 0;
        int result = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (freq[nums[right]] == 0) {
                k--;
            }
            freq[nums[right]]++;

            while (k < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) { // Adjust if the frequency becomes 0
                    k++;
                }
                left++;
            }

            result += right - left + 1;
        }

        return result;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
