class Solution {
    public List<Integer> pancakeSort(int[] A) {
        List<Integer> ans = new ArrayList<>();

        for (int valueToSort = A.length; valueToSort > 0; valueToSort--) {
            int index = this.find(A, valueToSort);
            if (index == valueToSort - 1)
                continue;
            if (index != 0) {
                ans.add(index + 1);
                this.flip(A, index + 1);
            }
            ans.add(valueToSort);
            this.flip(A, valueToSort);
        }

        return ans;
    }

    protected void flip(int[] sublist, int k) {
        int i = 0;
        while (i < k / 2) {
            int temp = sublist[i];
            sublist[i] = sublist[k - i - 1];
            sublist[k - i - 1] = temp;
            i += 1;
        }
    }

    protected int find(int[] a, int target) {
        for (int i = 0; i < a.length; i++)
            if (a[i] == target)
                return i;
        return -1;
    }
}