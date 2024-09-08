class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        priority_queue<pair<int, char>> maxHeap;
        for (auto &entry : freq)
            maxHeap.push({entry.second, entry.first});
        string res;
        while (!maxHeap.empty())
        {
            auto [freq, ch] = maxHeap.top();
            maxHeap.pop();
            res.append(freq, ch);
        }
        return res;
    }
};