class Solution {
    public int maxVowels(String s, int k) {
        int max=0;
        int cnt=0;
        Set<Character>vowels=Set.of('a','e', 'i', 'o', 'u');
        for(int i =0;i<s.length();i++){
            if(vowels.contains(s.charAt(i)))cnt++;
            if(i>=k&&vowels.contains(s.charAt(i-k)))cnt--;
            max=Math.max(max, cnt);
        }
        return max;
    }
}