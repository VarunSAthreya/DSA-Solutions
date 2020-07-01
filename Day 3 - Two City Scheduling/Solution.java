class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int cost = 0;
        ArrayList<Integer> arrls = new ArrayList<>(); // to store difference value
        for (int[] i : costs) {
            cost += i[0]; // adding the costs if only travelled to a
            arrls.add(i[1] - i[0]);// difference in cost if travelled to b instead of a
        }
        Collections.sort(arrls);
        for (int i = 0; i < costs.length / 2; i++) {
            cost += arrls.get(i);// adding the difference
        }
        return cost;
    }
}