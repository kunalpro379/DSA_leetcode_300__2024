class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       int n=tickets.size();
        vector<int>line(tickets);//copy of ticket array 
        int time=0;
        while(line[k]>0){
                for(int i=0;i<n;i++){
                    if(line[i]>0){
                        line[i]--;
                        time++;
                        if(i==k&& line[i]==0){
                            return time;
                        }
                    }
                }
        }
    return time;   
    }
};