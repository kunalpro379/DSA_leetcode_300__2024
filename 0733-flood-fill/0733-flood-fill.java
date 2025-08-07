class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int currentColor=image[sr][sc];
        if(currentColor==color)return image;
        DFS(image, sr,sc,currentColor, color);
        return image;
    }
    private void DFS(int[][] image , int r, int c, int color, int newcolor){

        if (r < 0 || r >= image.length || c < 0 || c >= image[0].length) return;
    if(image[r][c]!=color)return;
    image[r][c]=newcolor;
    DFS(image, r + 1, c, color, newcolor);
    DFS(image, r , c+1, color, newcolor);
    DFS(image, r -1, c, color, newcolor);
    DFS(image, r , c-1, color, newcolor);
    }
}