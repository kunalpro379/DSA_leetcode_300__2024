#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>>result;
     if(numRows==0){
         return result;
     }
     result.push_back({1});
     for(int i=1;i<numRows;i++){
         vector<int>row(i+1,1);
         for(int j=1;j<i;j++){
             row[j]=result[i-1][j-1]+result[i-1][j];
         }
        result.push_back(row); 
     }
     return result;

    }
};