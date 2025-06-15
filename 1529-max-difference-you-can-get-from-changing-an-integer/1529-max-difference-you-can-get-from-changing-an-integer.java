class Solution {
    public int maxDiff(int num) {
        String s = Integer.toString(num);
        
        // To maximize:
        char[] maxArr = s.toCharArray();
        for (int i = 0; i < maxArr.length; i++) {
            if (maxArr[i] != '9') { // first non-9 we find
                char toChange = maxArr[i];
                
                for (int j = 0; j < maxArr.length; j++) {
                    if (maxArr[j] == toChange) {
                        maxArr[j] = '9';
                    }
                }
                
                break;
            }
        }
        int maxVal = Integer.parseInt(new String(maxArr));

        // To minimize:
        char[] minArr = s.toCharArray();

        if (minArr[0] != '1') { // first is not '1'
            char toChange = minArr[0];
            for (int j = 0; j < minArr.length; j++) {
                if (minArr[j] == toChange) {
                    minArr[j] = '1';
                }
            }
        } else { // first is already '1'
            boolean changed = false;
            for (int i = 1; i < minArr.length; i++) {
                if (minArr[i] != '0' && minArr[i] != '1') {
                    char toChange = minArr[i];
                    for (int j = i; j < minArr.length; j++) {
                        if (minArr[j] == toChange) {
                            minArr[j] = '0';
                        }
                    }
                    changed = true;
                    break;
                }
            }
            // If we didn't find a non-0 or non-1, we leave it as-is.
        }
        
        int minVal = Integer.parseInt(new String(minArr));

        return maxVal - minVal;
    }
}
