class Solution {
    public int minMaxDifference(int num) {
        String numStr = String.valueOf(num);
        
        // To maximize:
        char maxTarget = '\0';
        for (int i = 0; i < numStr.length(); i++) {
            if (numStr.charAt(i) != '9') { 
                maxTarget = numStr.charAt(i);
                break;
            }
        }
        String maxStr = (maxTarget == '\0') ? numStr : numStr.replace(maxTarget, '9'); 
        int max = Integer.parseInt(maxStr);
        
        // To minimize:
        char minTarget = '\0';
        String minStr = numStr;
        for (int i = 0; i < numStr.length(); i++) {
            if (numStr.charAt(i) != '0') { 
                minTarget = numStr.charAt(i);
                break;
            }
        }
        if (minTarget != '\0') {
            minStr = numStr.replace(minTarget, '0'); 
        }
        int min = Integer.parseInt(minStr);
        
        return max - min;
    }
}
