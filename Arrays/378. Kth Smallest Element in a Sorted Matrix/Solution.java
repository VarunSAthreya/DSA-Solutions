class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int[] array = new int[matrix.length * matrix[0].length];
        int count = 0;
        // Converting to a single array
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                array[count++] = matrix[i][j];
            }
        }

        return quickSelect(array, k);
    }

    public int quickSelect(int[] array, int target) {
        int start = 0;
        int end = array.length - 1;

        while (start < end) {
            int partitionIndex = partition(array, start, end);
            if (partitionIndex == target - 1) {
                return array[target - 1];
            } else if (partitionIndex < target) {
                start = partitionIndex + 1;
            } else {
                end = partitionIndex - 1;
            }
        }

        return array[start];
    }

    public int partition(int[] array, int start, int end) {
        int pivot = array[(start + end) / 2];

        while (start < end) {
            while (array[start] < pivot)
                start++;
            while (array[end] > pivot)
                end--;

            if (array[start] > array[end]) {
                swap(array, start, end);

            } else {
                start++;
            }
        }
        return end;
    }

    public void swap(int[] array, int start, int end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
    }
}
