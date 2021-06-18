class Solution {

    int[] getData(int[] nums, int k) {

        Map<Integer, Integer> map = new HashMap();

        for (int i = 0; i < nums.length; i++) {

            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }

        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {

            pq.add(entry);
            if (pq.size() > k)
                pq.poll();
        }

        int[] ans = new int[k];
        int i = 0;
        while (k-- > 0) {

            int data = pq.poll().getKey();
            ans[i++] = data;

        }
        return ans;

    }

    public int[] topKFrequent(int[] nums, int k) {

        return getData(nums, k);

    }
}