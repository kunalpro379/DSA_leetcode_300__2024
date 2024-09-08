class Solution
{
public:
    int findMinimumOperations(string s1, string s2, string s3)
    {
        int i = 0;
        int minLen = min({s1.size(), s2.size(), s3.size()});
        while (i < minLen && s1[i] == s2[i] && s2[i] == s3[i])
            i++;

        if (i == 0)
            return -1;

        return s1.size() + s2.size() + s3.size() - i * 3;
    }
    //     //struct for creating a custom hash function
    //     struct HashTuple{
    //         size_t operator()(tuple<int, int, int >&t)const{
    //             auto h1=hash<int>{}(get<0>(t));
    //             auto h2=hash<int>{}(get<1>(t));
    //             auto h3=hash<int>{}(get<2>(t));
    //             return h1^h2^h3;  //combine the hash vals using XOR and return thre res
    //         }
    //     };
    //     int findMinimumOperations(string s1, string s2, string s3) {
    //         unordered_map<tuple<int, int, int>, int, HashTuple> memo;
    //         return findMinOps(s1,s2,s3,0,0,0,memo);
    //     }
    //     int findMinOps(string s1, string s2, string s3,int i , int j , int k, unordered_map<tuple<int, int, int>, int, HashTuple>&memo){
    //         //if we have reached the end of s3
    //         if(k==s3.size()){
    //             return (i==s1.size()&& j==s2.size)?0:INT_MAX;
    //         }
    //         //key for memorizn
    //         auto key =make_tuple(i,j,k);
    //         //
    //         if(memo.find(key)!=memo.end())return memo[key];

    //         int res=INT_MAX;
    //         //if the current char of s3 matches the current char of s1
    //         if(i<s1.size()&& s1[i]==s3[k]) res=min(res, findMinOps(s1,s2,s3,i+1,j,k+1, memo));
    //         //if the current char of s3 matches the current char of
    //         if(j<s2.size()&& s2[j]==s3[k]) res=min(res, findMinOps(s1,s2,s3,i,j+1,k+1, memo));
    //         //cost of removing the character from s1
    //         if(i<s1.size()) res=min(res,1+findMinOps(s1,s2,s3,i+1, j,k,memo));
    //         //cost of removing the character from s2
    //         if(j<s2.size()) res=min(res,1+findMinOps(s1,s2,s3,i, j+1,k,memo));
    //         memo[key]=res;
    //         return res;

    //     }
    //  int findMinimumOperations(string s1, string s2, string s3) {
    //     int n1=s1.size(),n2=s2.size(), n3=s3.size();
    //     int commonSuffixLength=findCommonSuffix(s1,s2,s3);
    //     return (n1-commonSuffixLength)+(n2-commonSuffixLength)+(n3-commonSuffixLength);
    //  }
    //  int findCommonSuffix(string &s1, string &s2, string &s3){
    //     int i=s1.size()-1, j=s2.size()-1,k=s3.size()-1;
    //     int commonLength=0;
    //     while(i>=0&&j>=0&&k>=0&&s1[i]==s2[j]&&s2[j]==s3[k]){
    //         commonLength++;
    //         i--;
    //         j--;
    //         k--;
    //     }return commonLength;
    //  }
};
