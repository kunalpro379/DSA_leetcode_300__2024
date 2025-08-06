class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>>anagram=new HashMap<>();
        // char[] charr=strs.toCharArray();
        // Arrays.sort(charr);
        for(String str:strs){
            char[] charr=str.toCharArray();
            Arrays.sort(charr);
            String key = new String(charr); 

            anagram.computeIfAbsent(key, x -> new ArrayList<>()).add(str);
        }
        // String key=new String(str);
        return new ArrayList<>(anagram.values());


    }
}