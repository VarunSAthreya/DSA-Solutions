class RandomizedSet {
    List<Integer> nums;
    Map<Integer, Integer> position;

    /** Initialize your data structure here. */
    public RandomizedSet() {
        nums = new ArrayList();
        position = new HashMap();
    }

    /**
     * Inserts a value to the set. Returns true if the set did not already contain
     * the specified element.
     */
    public boolean insert(int val) {
        if (position.containsKey(val))
            return false;
        nums.add(val);
        position.put(val, nums.size() - 1);
        return true;
    }

    /**
     * Removes a value from the set. Returns true if the set contained the specified
     * element.
     */
    public boolean remove(int val) {
        if (!position.containsKey(val))
            return false;
        int pos = position.get(val);
        nums.set(pos, nums.get(nums.size() - 1));
        position.put(nums.get(pos), pos);
        nums.remove(nums.size() - 1);
        position.remove(val);
        return true;
    }

    /** Get a random element from the set. */
    public int getRandom() {
        return nums.get((int) (Math.random() * nums.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet(); boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val); int param_3 = obj.getRandom();
 */