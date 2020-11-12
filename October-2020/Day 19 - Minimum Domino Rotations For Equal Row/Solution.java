class Solution {
    public int minDominoRotations(int[] A, int[] B) {

        int min=Integer.MAX_VALUE;
        for(int i=1;i<=6;i++){
            min = Math.min(min,solve(A,B,i));
            min = Math.min(min, solve(B,A,i));
        }
        return min == Integer.MAX_VALUE?-1:min;
    }

    private int solve(int[] a, int[] b, int x) {
        int res=0;
        for(int i = 0;i<a.length;i++){
            if(a[i] == x) continue;

            if(b[i] != x)
                return Integer.MAX_VALUE;
            res++;
        }
        return res;
    }
}