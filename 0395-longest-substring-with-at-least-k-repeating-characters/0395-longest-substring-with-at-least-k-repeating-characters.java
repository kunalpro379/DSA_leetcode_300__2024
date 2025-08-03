class Solution {
    public int longestSubstring(String s, int k) {
            int maxLen = 0;
            int maxUnique = getMaxUniqueLetters(s);
            for (int targetUnique = 1; targetUnique <= maxUnique; targetUnique++) {
                int[] freq = new int[26];
                int start = 0, end = 0;
                int unique = 0, countAtLeastK = 0;
                while(end<s.length()){
                    if (unique <= targetUnique) {
                        int idx = s.charAt(end) - 'a';
                        if (freq[idx] == 0) unique++;
                        freq[idx]++;
                        if (freq[idx] == k) countAtLeastK++;
                        end++;
                    } else {
                        int idx = s.charAt(start) - 'a';
                        if (freq[idx] == k) countAtLeastK--;
                        freq[idx]--;
                        if (freq[idx] == 0) unique--;
                        start++;
                    }            
                    if (unique == targetUnique && unique == countAtLeastK) {
                maxLen = Math.max(maxLen, end - start);
            }               
                 }

            }    return maxLen;

    }
    
    private int getMaxUniqueLetters(String s) {
        boolean[] seen = new boolean[26];
        int count = 0;
        for (char c : s.toCharArray()) {
            if (!seen[c - 'a']) {
                seen[c - 'a'] = true;
                count++;
            }
        }
        return count;
    }
}