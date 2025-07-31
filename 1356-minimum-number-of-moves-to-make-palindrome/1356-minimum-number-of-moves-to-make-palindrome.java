class Solution {
    public int minMovesToMakePalindrome(String s) {
        char[] arr=s.toCharArray();
        int moves=0;
        int left=0, right=arr.length-1;
        while(left<right){
            if(arr[left]==arr[right]){
                left++;
                right--;
            }
            // else if(arr[left]!=arr[right]){
            else{
                int k=right;
                while(k>left&&arr[k]!=arr[left]){
                    k--;
                }
                if(k==left)//middle one 
                {
                    swap(arr, left, left+1);
                    moves++;

            }else{
                //bring the mathcking k to the right swapping one by one adjacent
                for(int i=k;i<right;i++){
                    swap(arr,i,i+1);
                    moves++;
                }
                left++;
                right--;
            }
        }
    }return moves;
    }
        private void swap(char[] arr, int i, int j) {
            arr[i] = (char)(arr[i] + arr[j]);
            arr[j] = (char)(arr[i] - arr[j]);
            arr[i] = (char)(arr[i] - arr[j]);
        }

}