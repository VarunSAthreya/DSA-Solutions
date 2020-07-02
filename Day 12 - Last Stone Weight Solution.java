class Solution {
    public int lastStoneWeight(int[] stones) {
        ArrayList<Integer> arr= new ArrayList<Integer>();
        for(int x : stones){
            arr.add(x);
        }
        
        while(arr.size()>1){
            Collections.sort(arr, Collections.reverseOrder());
            if(arr.get(0)==arr.get(1)){
                arr.remove(0);
                arr.remove(0);
            }
            else{
                arr.set(0, arr.get(0)-arr.get(1));
                arr.remove(1);
            }
        }
        if(arr.size()>0)
            return arr.get(0);
        else
            return 0;
    }
}
        
    
