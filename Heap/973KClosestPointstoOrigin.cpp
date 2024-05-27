class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        //   priority_queue<pair<int, vector<int>>> minHeap;
        // maxheapp
        /*
         for (const auto& point : points) {
                    int distance = point[0] * point[0] + point[1] * point[1];// constant time
                    //iterating took O(n)
                   minHeap.push({distance,point}); //pushing in pq takes O(logk)  time
                   if(minHeap.size()>k){//maintaining size of queue not more than k
                    minHeap.pop();
                   }}
                   vector<vector<int>>result;
                   while(!minHeap.empty()){
                    result.push_back(minHeap.top().second);
                   }
                   //from farthest point to closest
                   reverse(result.begin(), result.end());
                   return result;
            */

        // custom coparator
        auto comp = [](const vector<int> &p1, const vector<int> &p2)
        {
            return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);
        for (const auto &point : points)
        {
            minHeap.push(point);
            if (minHeap.size() > k)
                minHeap.pop();
        }
        vector<vector<int>> res;
        while (!minHeap.empty())
        {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};