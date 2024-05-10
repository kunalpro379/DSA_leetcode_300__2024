class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //UNorderedMap
        //unordered_map<int, int >m;  avg case search time O(1)
        vector<int>m(k,0);
        m[0]=1;
        int prefSum=0,rem,total=0;
        for(int i=0;i<nums.size();i++){
            prefSum+=nums[i];
            rem=((prefSum%k)+k)%k;
            //if(rem<0)rem=k+rem;

            total+=m[rem];
            m[rem]++;
            // if(m.count(rem)){
            //     total+=m[rem];
            //     m[rem]++;
            // }else{
            //     m[rem]=1;
            // }
        }return total;

    }
};