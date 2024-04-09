class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int>NumFreq;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            NumFreq[nums[i]]++;
            if(NumFreq[nums[i]]>1){
                res.push_back(nums[i]);
            }
        }
        return res;
        
    }
};