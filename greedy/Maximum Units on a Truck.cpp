#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:


    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(),[](const vector<int>&a, vector<int>&b){
            return a[1]>b[1];
        });       
         int finalVal=0;
        int i =0;
        while(i<boxTypes.size()&&truckSize>0){
                if(truckSize-boxTypes[i][0]>0){
                truckSize-=boxTypes[i][0];
                    finalVal+=boxTypes[i][0]*boxTypes[i][1];
                }
                else{
                    finalVal+=truckSize*boxTypes[i][1];
                    truckSize=0;
                    break;
                }
                i++;
        }
        return finalVal;
    }
};