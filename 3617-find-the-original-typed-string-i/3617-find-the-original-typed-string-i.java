class Solution {
    public int possibleStringCount(String word) {
        Set<String >possible=new HashSet<>();
        possible.add(word);
        int n=word.length();
        for(int i=0;i<n;){
            int j=i;
            //find the group of same chars
            while(j<n&& word.charAt(j)==word.charAt(i))j++;
            int len=j-i;
            if(len>1){
                for(int k=1;k<len;k++){
                    String reducedGroup = String.valueOf(word.charAt(i)).repeat(k);
                    String newWord = word.substring(0, i) + reducedGroup + word.substring(j);
                    possible.add(newWord);
                }
                //try reducing this group to length 1;
                // String newWord=word.substring(0,i)+word.charAt(i)+word.substring(j);
                // possible.add(newWord);
            }
            i=j;

        }return possible.size();
    }
}