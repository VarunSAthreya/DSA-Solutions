class MyHashSet {
    List<Integer> hashSet;

    /** Initialize your data structure here. */
    public MyHashSet() {
        hashSet = new ArrayList<>();
    }

    public void add(int key) {
        if (!hashSet.contains(key))
            hashSet.add(key);
    }

    public void remove(int key) {
        if (hashSet.contains(key))
            hashSet.remove(new Integer(key));
    }

    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return hashSet.contains(key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such: MyHashSet obj
 * = new MyHashSet(); obj.add(key); obj.remove(key); boolean param_3 =
 * obj.contains(key);
 */