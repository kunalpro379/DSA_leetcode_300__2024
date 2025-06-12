class Solution {
    public String reverseWords(String s) {
        int right=s.length()-1;
        StringBuilder res=new StringBuilder();
        while(right>=0){
            while(right>=0&&s.charAt(right)==' '){
                right--;
            }
            // if(right<0)break;
            int left=right;
            // take one word
            while(left>=0&&s.charAt(left)!=' ')left--;
            //extract word
            res.append(s.substring(left+1, right+1));
            res.append(' ');
            right=left-1;
        }
        return res.toString().trim();
    }
}