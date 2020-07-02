class Solution {
    public int arrangeCoins(int n) {
        long k = (long)Math.sqrt(2 * (long) n);
        long sum = k*(k+1)/2;
        if(sum > n) return (int)k-1;
        return (int)k;
    }
}