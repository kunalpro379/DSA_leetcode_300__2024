class Solution {
    public int minimumDeletions(String word, int k) {
        int[] cnt = new int[26];
        for (char c : word.toCharArray()) {
            cnt[c - 'a']++;
        }

        int ans = Integer.MAX_VALUE;

        // Use 'minFreq' here – same as in loop header
        for (int minFreq : cnt) {
            int deletions = 0;

            for (int freq : cnt) {
                if (freq < minFreq) {
                    deletions += freq;
                } else if (freq > minFreq + k) {
                    deletions += freq - (minFreq + k);
                }
            }

            ans = Math.min(ans, deletions);
        }

        return ans;
    }
}
