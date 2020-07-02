class LRUCache {
    private int _capacity;
    private LinkedHashMap<Integer,Integer> _map;

    public LRUCache(int capacity) {
        _capacity = capacity;
        _map = new LinkedHashMap<Integer,Integer>();
        
    }
    
    public int get(int key) {
        if(_map.containsKey(key)){
            int val = _map.get(key);
            _map.remove(key);
            _map.put(key,val);
            return val;
        }
        return -1;
    }
    
    public void put(int key, int value){ 
        if(_map.containsKey(key))
            _map.remove(key);
        else if(_map.size() == _capacity)
            _map.remove(_map.keySet().iterator().next());
        _map.put(key,value);
        
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
