class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> countMap; // count of each element
        unordered_set<int> freqT;         // unique freq
        for (int num : arr)
        {
            countMap[num]++;
        }
        for (auto &entry : countMap)
        {
            int freq = entry.second;
            if (freqT.find(freq) != freqT.end())
            {
                return false;
            }
            freqT.insert(freq);
        }
        return true;
    }
};