class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s==null&&s.length() == 0)return 0;
        int start = 0 , maxLength = 0;

        // char[] arr= s.toCharArray();
        int temp=0;
        HashMap<Character, Integer>map=new HashMap<Character, Integer>();
        for(int end=0;end<s.length();end++){
            char c = s.charAt(end);

            if(map.containsKey(c))start = Math.max(start, map.get(c) + 1);
            map.put(c,end);
            maxLength = Math.max(maxLength, end - start + 1);

        }return maxLength;
    }
}