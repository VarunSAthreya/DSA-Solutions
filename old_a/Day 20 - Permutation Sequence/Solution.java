class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> fact = new ArrayList<>(n);
        List<Integer> digits = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            fact.add(1);
            digits.add(1);
        }
        for (int i = 1; i < n; i++) {
            fact.set(i, fact.get(i - 1) * (i + 1));
            digits.set(i, i + 1);
        }

        String result = "";
        while (result.length() < n - 1) {
            int repeat = fact.get(fact.size() - 2);
            int next_digit = (k - 1) / repeat;
            result += Integer.toString(digits.get(next_digit));
            digits.remove(next_digit);
            fact.remove(fact.size() - 1);
            k = k % repeat;
            if (k == 0) {
                for (int i = digits.size() - 1; i >= 0; i--) {
                    result += Integer.toString(digits.get(i));
                }
            }
        }
        if (result.length() < n)
            result += Integer.toString(digits.get(0));

        return result;
    }
}