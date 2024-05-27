class Solution
{
public:
    bool containsNearbyDuplicate(const vector<int> &nums, int k)
    {
        std::vector<pair<int, int>> index_num;

        for (int i = 0; i < nums.size(); i++)
        {
            index_num.push_back({i, nums[i]});
        }

        std::sort(index_num.begin(), index_num.end());

        for (int i = 1; i < index_num.size(); i++)
        {
            if (index_num[i].second == index_num[i - 1].second && index_num[i].first - index_num[i - 1].first <= k)
            {
                return true;
            }
        }

        return false;
    }
};