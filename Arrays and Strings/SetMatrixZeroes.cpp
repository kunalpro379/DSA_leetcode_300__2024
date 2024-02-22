//SetMatrixZeroes.cpp
//Approach 1
class Solution {
public:

    // void row(vector<vector<int>>& matrix, int i){
    //     int m=matrix.size();
    //     int n=matrix[0].size();
    //     for (int j=0;j<n;j++){
    //         if(matrix[i][j]==0){
    //             for(int k=0;k<m;k++){
    //                 matrix[k][j]=0;
    //             }
    //             break; 
    //         }
    //     }
    // }
    
    // void col(vector<vector<int>>& matrix, int j){
    //     int m=matrix.size();
    //     int n=matrix[0].size();
    //     for (int i=0;i<m;i++){
    //         if(matrix[i][j]==0){
    //             for(int k=0;k<n;k++){
    //                 matrix[i][k]=0;
    //             }
    //             break; 
    //         }
    //     }
    // }
    
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m=matrix.size();
    //     int n=matrix[0].size();

    //     for(int j=0;j<n;j++){
    //         col(matrix,j); 
    //     }
    //     for(int i=0;i<m;i++){
    //         row(matrix,i); 
    //     }
    // }
      void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool firstrow=false;
        bool firstcol=false;
for(int i=0;i<m;i++){
if(matrix[i][0]==0){
    firstcol=true;
    break;
}
}
for(int j=0;j<n;j++){
if(matrix[0][j]==0){
    firstrow=true;
    break;
}
}

for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
        if(matrix[i][j]==0){
            matrix[i][0]=0;
            matrix[0][j]=0;
        }  
    }
}
for (int i=1;i<m;i++){
    if(matrix[i][0]==0){
for(int j=1;j<n;j++){matrix[i][j]=0;}
    }
}
for (int j=1;j<n;j++){
    if(matrix[0][j]==0){
for(int i=1;i<m;i++){matrix[i][j]=0;}
    }
}

if (firstrow) {
    for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
    }
}

if (firstcol) {
    for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
    }
}


    }
};
//Using hashing 

