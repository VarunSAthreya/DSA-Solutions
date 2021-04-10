class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        List<int[]> result = new ArrayList<>();
        int i = 0;
        int j = 0;
        while (i < A.length && j < B.length) {
            int[] a = A[i];
            int[] b = B[j];
            if (a[1] < b[0])
                i++;
            else if (b[1] < a[0])
                j++;
            else {// overlap
                int start = Math.max(a[0], b[0]);
                int end = Math.min(a[1], b[1]);
                result.add(new int[] { start, end });
                if (a[1] < b[1])
                    i++;
                else if (a[1] >= b[1])
                    j++;
            }
        }
        return result.toArray(new int[result.size()][]);
    }
}
