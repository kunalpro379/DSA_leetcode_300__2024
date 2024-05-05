class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // sort(deck.begin(), deck.end());
        // vector<int>res(deck.size());
        // vector<int>ind(deck.size());
        // for(int i=0;i<deck.size();i++){
        //     ind[i]=i;
        // }
        // int in=0;
        // for(int j=0;j<deck.size();j++){
        //     res[ind[in]]=deck[j];
        //     in++;
        //     if(ind_index<ind.size()-1){ind_index++;}
        //     i+=1;
        //     if(i+1<ind.size()){ind.push_back(ind[i+1]);}
        //     else 
        //     break;
        // }
        // ind.resize(deck.size());
        // return res;
        std::sort(deck.begin(),deck.end());
        queue<int>ind;
        for(int i=0;i<deck.size();++i){
            ind.push(i);
        }
        std::vector <int>res(deck.size(),0);
        for (int card: deck){
            res[ind.front()]=card;
            ind.pop();
            if(!ind.empty()){
                ind.push(ind.front());
                ind.pop();
            }
        }return res;
    }
};