// Solution 1
// O(N2) space

class Solution {
    public int findJudge(int N, int[][] nums) {
        if (nums.length < N - 1)
            return -1;

        int[] trusts = new int[N + 1];
        int[] trusted = new int[N + 1];
        for (int[] x : nums) {
            trusts[x[0]]++;
            trusted[x[1]]++;
        }
        for (int i = 1; i <= N; i++) {
            if (trusted[i] == N - 1 && trusts[i] == 0)
                return i;
        }
        return -1;
    }
}

// Solution 2
// O(N) space

class Solution {
    public int findJudge(int N, int[][] nums) {
        if (nums.length < N - 1)
            return -1;

        int[] trusts = new int[N + 1];
        for (int[] x : nums) {
            trusts[x[0]]--;
            trusts[x[1]]++;
        }
        for (int i = 1; i <= N; i++) {
            if (trusts[i] == N - 1)
                return i;
        }
        return -1;
    }
}
