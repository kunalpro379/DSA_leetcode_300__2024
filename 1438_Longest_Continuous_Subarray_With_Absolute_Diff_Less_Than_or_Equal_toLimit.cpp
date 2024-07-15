
// time limit exceeding (use of min/max heap)
//  class Solution {
//  public:
//  typedef pair<int, int>P;
//      int longestSubarray(vector<int>& nums, int limit) {
//  int n=nums.size();
//  priority_queue<P, vector<P>>maxPq;//max_heap
//  priority_queue<P, vector<P>, greater<P>>minPq;
//  int i=0;
//  int j=0;
//  int maxlen=0;
//  while(j<n){//n times
//      maxPq.push({nums[j], j});
//      minPq.push({nums[j], j});
//      while(maxPq.top().first-minPq.top().first>limit){
//          i=min(maxPq.top().second, minPq.top().second)+1;
//          while(maxPq.top().second<1){
//              maxPq.pop();//logn time
//          }
//          while(minPq.top().second<i){
//              minPq.pop();//logn time
//          }
//      }maxlen=max(maxlen,j-i+1);
//      j++;

// }return maxlen;

//     }
// };
// TC--->O(2nlogn )
// SC-->O(2n)

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        multiset<int> st;
        int i = 0;
        int j = 0;
        int maxlen = 0;
        while (j < n)
        { // n times
            st.insert(nums[j]);
            while (*st.rbegin() - *st.begin() > limit)
            {
                st.erase(st.find(nums[i]));
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
};
// TC--> O(nlogn)
// SC--->O(n)