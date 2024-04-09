class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int >>res;
        vector<int >current ;
        backtrack(candidates,target,0,current,res);
        return res;
    }
    void backtrack(vector<int>& candidates, int target, int start, vector<int>&current, vector<vector<int>>&res){
        if (target<0){
            return;
        }
        if(target==0){
            res.push_back(current);
            return;
        }
        for (int i=start;i<candidates.size();i++){
            current.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i,current,res);
            current.pop_back();
        }
    }
};