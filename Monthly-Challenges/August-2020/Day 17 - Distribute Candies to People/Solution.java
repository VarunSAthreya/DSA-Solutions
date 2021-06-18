class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];
        int curDistributedTotal = 0;
        int thisPplGet = 1;
        int thisPpl = 0;
        while (candies - curDistributedTotal >= thisPplGet) {
            res[thisPpl] += thisPplGet;
            curDistributedTotal += thisPplGet;
            thisPpl = nextPpl(num_people, thisPpl);
            thisPplGet += 1;
        }
        res[thisPpl] += candies - curDistributedTotal;
        return res;
    }

    private static int nextPpl(int num_people, int thisPpl) {
        if (thisPpl == num_people - 1)
            return 0;
        return thisPpl + 1;
    }
}