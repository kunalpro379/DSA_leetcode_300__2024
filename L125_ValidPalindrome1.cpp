class Solution {
public:
    bool isPalindrome(string s) {
        
//  int len = s.length();    

//         int i = 0;
//         int j = len - 1;

//         while (i <= j) {
//             if (s[i] != s[j]) {
//                 return false;
//             }
//             i++;
//             j--;
//         }

//         return true;
    int left =0;
    int right=s.size()-1;
    while(left<right){
        while(left<right&& !isalnum(s[left])){left++;}

        while(left<right&& !isalnum(s[right])){right--;}

        if(tolower(s[left])!=tolower(s[right])){return false;}
        left++;
        right--;

    }
    return true;

    }
};