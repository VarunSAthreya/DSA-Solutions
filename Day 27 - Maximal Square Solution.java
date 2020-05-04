class Solution {
    public int maximalSquare(char[][] matrix) {
    if(matrix == null || matrix.length ==0){
        return 0;
    }
    int row = matrix.length;
    int col = matrix[0].length;
    int max = '0';
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]!='0' && i!=0 && j!=0){
                matrix[i][j]= (char)(Math.min(Math.min(matrix[i-1][j]-'0',matrix[i][j-1]-'0'),matrix[i-1][j-1]-'0')+1+'0');
            }
            if(matrix[i][j]>max){
                max = matrix[i][j];
            }
        }
    }
    return (max-'0')*(max-'0');
}
}
