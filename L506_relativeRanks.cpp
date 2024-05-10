class Solution {
public:


    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<pair<int, int >>indexed_scores;
        for(int i=0;i<n;i++){
            indexed_scores.emplace_back(score[i],i);
        }
        sort(indexed_scores.begin(), indexed_scores.end(),
        [](const pair<int, int>&a, const pair<int, int >&b){
            return a.first >b.first;
        });
        vector<string>res(n);
        for(int rank=0;rank<n;rank++){
            int i=indexed_scores[rank].second;
            if(rank==0){
                res[i]="Gold Medal";
            }else if(rank==1){
                res[i]="Silver Medal";
            }else  if(rank==2){
                res[i]="Bronze Medal";
            }else{
                res[i]=to_string(rank+1);
            }
        }return res;

    }

    //using priority queue
    // vector<string> findRelativeRanks(vector<int>& score) {
    //         int n=score.size();
    //         priority_queue<pair<int, int>>PQ;
    //         for(int i=0;i<n;i++){
    //             PQ.push({score[i],i});
    //         }
    //         vector<string>res(n);
    //         for(int rank=1;!PQ.empty();rank++){
    //             int idx=PQ.top().second;
    //             PQ.top();
    //             if (rank == 1) {
    //             res[idx] = "Gold Medal";
    //         } else if (rank == 2) {
    //             res[idx] = "Silver Medal";
    //         } else if (rank == 3) {
    //             res[idx] = "Bronze Medal";
    //         } else {
    //             res[idx] = std::to_string(rank);
    //         }
                
    //         }return res;
    // }




};