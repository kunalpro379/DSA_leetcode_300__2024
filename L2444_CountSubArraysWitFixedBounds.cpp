class Solution {
public:

    long long countFixedBoundSubArrays(vector<int>& nums,  int minK, int maxK){
        long long res=0;
        int winStart=0;
       // deque<int >indices;//for elements in the curr window
        //for(int winEnd=0;winEnd<nums.size();winEnd++){
        //         if(nums[winEnd]==bound){
        //             indices.push_back(winEnd);//storing index
        //             int count=winEnd-winStart+1;//len of subArr
        //             res+=count;

        //         }else{//adjusting window
        //             while(!indices.empty()&&nums[indices.back()]<bound){
        //                 indices.pop_back();
        //             }
        //             if(!indices.empty()){
        //                 int lastInd=indices.back();
        //                 int count=lastInd-winStart+1;
        //                 res+=count;
        //             }else{
        //                 winStart=winEnd+1;
        //             }
        //         }
        // if(nums[winEnd]==bound){indices.push_back(winEnd);//store the index of curr element
        // }else{
        //     //adjusting window
        //     indices.clear();
        //     winStart=winEnd+1;
        // }
        // res+=winEnd-winStart+1;
        //  }

        //
        // unordered_map<int , int>lastInd;
        // for(int winEnd=0;winEnd<nums.size();winEnd++){
        //     lastInd[nums[winEnd]]=winEnd;
        //     //if both min and max present in the map

        //     if(lastInd.count(minK)&&lastInd.count(maxK)){
        //         int lastMinInd=lastInd[minK];
        //         int lastMaxInd=lastInd[maxK];
        //         winStart=min(lastMinInd, lastMaxInd)+1;
        //         res+=winEnd-winStart+1;
        //     }
        // }
         return res;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        //return countFixedBoundSubArrays(nums,minK,maxK)-countFixedBoundSubArrays(nums,minK-1,maxK);
        long long ans=0;
        int minKpos=-1;
        int maxKpos=-1;
        int end=-1;
        for(int i=0;i<nums.size();i++){
                // [1,3,5,2,7,5] min=1  max=5

            if(nums[i]==minK)
                minKpos=i;
            if(nums[i]==maxK)
                maxKpos=i;
            if(nums[i]<minK||nums[i]>maxK)
                end=i;

            long long smaller=min(minKpos,maxKpos);
            long long temp=smaller-end;
            ans+=(temp<=0)?0:temp;
        }
        return ans;
    }
};