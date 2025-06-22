class Solution {
    public String[] divideString(String s, int k, char fill) {
        List<String>res=new ArrayList<>();
        for(int i=0;i<s.length();i+=k){
            int end=Math.min(i+k,s.length());
            String grp=s.substring(i,end);
            if(grp.length()<k){
                StringBuilder sb=new StringBuilder(grp);
                // while(sb.length()<s.length())sb.append(fill);
                while(sb.length()<k)sb.append(fill);

                grp=sb.toString();
            }res.add(grp);
        }return res.toArray(new String[0]);
    }
}