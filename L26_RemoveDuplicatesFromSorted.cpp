class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){return 0;}
        int temp=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[temp-1]){
                if(i!=temp){nums[temp]=nums[i];}
                temp++;
            }
        }    return temp;

// queue<int> q;
// unordered_set<int> seen;

//     for (int num : nums) {
//                 if (seen.find(num) == seen.end()) {
//                 q.push(num);
//                 seen.insert(num);
//             }
//         }

//     int index = 0;
//         while (!q.empty()) {
//             nums[index++] = q.front();
//             q.pop();
//         }

//         return index;
    }
};