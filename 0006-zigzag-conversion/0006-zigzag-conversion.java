class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1||s.length()<=numRows)return s;
        StringBuilder[] rows=new StringBuilder[numRows];
        for(int i=0;i<numRows;i++){
            rows[i]=new StringBuilder();
        }
        int currRow=0;
        boolean down=false;
        for(char c: s.toCharArray()){
            rows[currRow].append(c);
            if(currRow==0||currRow==numRows-1)down=!down;
            currRow+=down?1:-1;
        }
        StringBuilder res=new StringBuilder();
        for(StringBuilder row: rows)res.append(row);
        return res.toString();
    }
}