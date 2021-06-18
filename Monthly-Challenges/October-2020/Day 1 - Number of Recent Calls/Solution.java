class RecentCounter {
    Deque<Integer> queue = new ArrayDeque<>();

    public RecentCounter() {

    }

    public int ping(int t) {
        while (!queue.isEmpty()) {
            int val = queue.peek();
            if (val < t - 3000) {
                queue.poll();
            } else {
                break;
            }
        }
        queue.offer(t);
        return queue.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter(); int param_1 = obj.ping(t);
 */