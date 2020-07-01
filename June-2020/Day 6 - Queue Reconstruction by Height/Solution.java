import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[][] reconstructQueue(int[][] people) {
        List<int[]> result = new ArrayList<>();

        Arrays.sort(people, (a, b) -> {
            return (a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        });

        for (int[] x : people) {
            result.add(x[1], x);
        }

        return result.toArray(new int[people.length][2]);
    }
}