class Solution
{
public:
    // int largestAltitude(vector<int>& gain) {
    //     int current_alt=0;
    //     int highest_alt=0;
    //     for(int g:gain){
    //         current_alt+=g;
    //         highest_alt=max(highest_alt, current_alt);
    //     }
    //     return highest_alt;
    // }

    // prefix sum
    int largestAltitude(vector<int> &gain)
    {
        int n = gain.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + gain[i];
        }
        int highest_alt = 0;
        for (int alt : prefixSum)
        {
            highest_alt = max(highest_alt, alt);
        }
        return highest_alt;
    }
};