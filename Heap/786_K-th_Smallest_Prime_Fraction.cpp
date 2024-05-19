class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<vector<double>>pq ;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double div=(double)arr[i]/arr[j];
                pq.push(vector<double>{div,(double)arr[i] ,(double)arr[j] });
                if(pq.size()>k)
                    pq.pop();
            }
        }
        auto vec=pq.top();
        vector<int>res(2);
        res[0]=vec[1];
        res[1]=vec[2];
        return res;
    }
};