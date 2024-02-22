#include<vector>
#include<iostream>
using namespace std;
//////////////////// Recursive solution /////////////////////////
int foo(int ind, int sum, vector<int>&arr) {
if(sum==0) return 1;
if(ind==0) return (arr[0]==sum);
int notChoose= foo(ind-1,sum,arr) ;
int choose=0;
if(arr[ind]<=sum)
choose=    foo(ind-1,sum-arr[ind],arr) ;

return choose +notChoose;
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	return foo(n-1,k,arr);
}
////////////////////// Memoization //////////////////////////////
int foo(int ind, int sum, vector<int>&arr,    vector<vector<int>>&dp) {
if(sum==0) return 1;
if(ind==0) return (arr[0]==sum);
if(dp[ind][sum]!=-1) return dp[ind][sum];
int notChoose= foo(ind-1,sum,arr) ;
int choose=0;
if(arr[ind]<=sum)
choose=foo(ind-1,sum-arr[ind],arr,dp) ;

return dp[ind][sum]=choose +notChoose;
}
int findWays(vector<int>& arr, int k)
{

	int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return foo(n-1,k,arr,dp);
}
////////////////tabulation////////////////////////
int findWays(vector<int>& arr, int k)
{
	

	int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,0));

    for (int i=0;i<n;i++) {
		dp[i][0]=1;
    }
    if (arr[0]<=k) {
    dp[0][arr[0]]=1;
	}
        for (int ind=1;ind<n;ind++) {
    		for (int sum=0;sum<=k;sum++) {
				int notChoose= dp[ind-1][sum];
				int choose=0;
				if(arr[ind]<=sum)
					choose=dp[ind-1][sum-arr[ind]];
				
				 dp[ind][sum]=choose +notChoose;
		}
}
        return dp[n-1][k];
}
