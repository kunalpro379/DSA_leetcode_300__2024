#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq; 
        long long count = 0;
        int prefixSum = 0;

        prefixSumFreq[0] = 1;

        for (int num : nums) {
            prefixSum += num;
            int targetSum = prefixSum - k; 
            
            if (prefixSumFreq.find(targetSum) != prefixSumFreq.end()) {
                count += prefixSumFreq[targetSum];
            }
            
            prefixSumFreq[prefixSum]++;
        }

        return count;
    }
};
