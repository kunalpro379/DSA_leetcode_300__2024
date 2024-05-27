class Solution
{
public:
    int dfs(vector<int> &nums, int idx, int k, unordered_map<int, int> &mp)
    {
        if (idx == nums.size())
            return 1;
        int taken = 0;
        if (!mp[nums[idx] - k] && !mp[nums[idx] + k])
        {
            mp[nums[idx]]++;
            taken = dfs(nums, idx + 1, k, mp);
            mp[nums[idx]]--;
        }
        int nottaken = dfs(nums, idx + 1, k, mp);
        return taken + nottaken;
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        int ans = dfs(nums, 0, k, mp);
        return ans - 1;
    }

    /*

     int dfs(vector<int>& nums,int idx ,int k,unordered_map<int, int>&mp){
         if(idx==nums.size()) return 1;

         if(mp.find(idx)!=mp.end())return mp[idx];
         int taken=0;
         if(!mp[nums[idx]-k]&&!mp[nums[idx]+k]){
             mp[nums[idx]]++;
             taken=dfs(nums,idx+1,k,mp);
             mp[nums[idx]]--;
         }
         int nottaken=dfs(nums,idx+1,k,mp);
         mp[idx]= taken+nottaken;
         return mp[idx]
     }
  int beautifulSubsets(vector<int>& nums, int k) {

     unordered_map<int, int>mp;
     int ans=dfs(nums,0,k,mp);
     return ans-1;
     }
    */
    // }
    // int res;
    // int K;
    // unordered_map<string, int>memo;
    // void solve(int idx, int k,vector<int>nums, unordered_map<int, int>&map){
    //     if(idx>=nums.size()){res++; return;}

    //     if(memo.find(k)!=memo.end()) return memo[key];
    //     //not take
    //     int cnt=solve(idx+1,nums,k,map);
    //     //take
    //     if(!map[nums[idx]-K]&&!map[nums[idx]+K]){
    //             map[nums[idx]]++;
    //             cnt+=solve(idx+1,k,nums,map);
    //             map[nums[idx]]--;
    //     }
    //     memo[k]=cnt;
    //     return cnt;
    // }

    // int beautifulSubsets(vector<int>& nums, int k) {
    //   res=0;
    //   K=k;
    //   unordered_map<int, int >map;
    //   solve(0,k,nums,map);
    //   return res-1;//excluding empty set
    // }

    // TLE Backtracking ////////////////////////////////////////////////////

    // int res;
    // int K;
    // void solve(int idx, vector<int>nums, unordered_map<int, int>&map){
    //     if(idx>=nums.size()){res++; return;}
    //     //not take
    //     solve(idx+1,nums,map);
    //     //take
    //     if(!map[nums[idx]-K]&&!map[nums[idx]+K]){
    //             map[nums[idx]]++;
    //             solve(idx+1,nums,map);
    //             map[nums[idx]]--;
    //     }
    // }

    // int beautifulSubsets(vector<int>& nums, int k) {
    //   res=0;
    //   K=k;
    //   unordered_map<int, int >map;
    //   solve(0,nums,map);
    //   return res-1;//excluding empty set
    // }

    // approach 2///////////////////////////////////////////////////
    //  int beautifulSubsets(vector<int>& nums, int k) {
    //      int cnt=0;
    //      vector<int>path;
    //      backtrack(nums, k, 0, path, cnt);
    //      return cnt;
    //  }
    //  void backtrack(vector<int>&nums,int k, int start, vector<int>&path, int &cnt){
    //      if(!path.empty()){
    //          bool valid=true;
    //          for(int i=0;i<path.size();i++){
    //              for(int j=i+1;j<path.size();j++){
    //                  if(abs(path[i]-path[j])==k){
    //                      valid=false;
    //                      break;
    //                  }
    //              }
    //              if(!valid) break;
    //          }if(valid )cnt++;
    //      }
    //      for(int i=start;i<nums.size();i++){
    //          path.push_back(nums[i]);
    //          backtrack(nums,k,i+1,path,cnt);
    //          path.pop_back();
    //      }
    //  }
};