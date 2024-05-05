class Solution {
public:
    int t[101][101];
    int countsteps(int ringindex, int i, int n){
        int dist=abs(i-ringindex);
        int wraparound=n-dist;
        return min(dist , wraparound);
    }

    int solve(int ringindex, int keyindex, string& ring , string& key){
        if(keyindex==key.length()){return 0;}
        int res=INT_MAX;
        if(t[ringindex][keyindex]!=-1){
            return t[ringindex][keyindex];
        }
        for(int i=0;i<ring.length();i++){
            if(ring[i]==key[keyindex]){
                int totalsteps=countsteps(ringindex,i,ring.length())+1+solve(i,keyindex+1,ring,key);
                res=min(res, totalsteps);
            }
        }return t[ringindex][keyindex]=res;
    }
    int findRotateSteps(string ring, string key) {
        memset(t,-1,sizeof(t));
        return solve(0,0,ring,key);
    }
};