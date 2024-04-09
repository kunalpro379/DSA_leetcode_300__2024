#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
      int maxLen=0;
    //   int currentSum=0;
      int left;
      unordered_map<int,int >freqMap;

      for(int right=0;right<nums.size();right++){
        // currentSum+=nums[j];
        // if(currentSum){}
        freqMap[nums[right]]++;
        while(freqMap[nums[right]]>k){
            freqMap[nums[left]]--;
            left++;
        }
        maxLen=max(maxLen,right-left+1);
      }
      return maxLen;
    }
};
