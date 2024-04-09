class Solution {
public:

int rows , cols;
bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int k){
    if(k==word.length()){return true;}

        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k]) return false;

    char temp=board[i][j];
    board[i][j]='y';//visited
    bool found=backtrack(board,word,i+1,j,k+1)||backtrack(board,word,i-1,j,k+1)||backtrack(board,word,i,j+1,k+1)||backtrack(board,word,i,j-1,k+1);
    board[i][j]=temp;
    return found;

}
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()){
            return false;
        
        }
        rows =board.size();
        cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                    if(board[i][j]==word[0] and backtrack(board,word,i,j,0)){
                        return true;//word found return tru
                        break;
                    }
            }
        }
         return false;
    }
};