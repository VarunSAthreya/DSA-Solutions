class KthLargest
{
public:
    multiset<int> ms;
    int ind = 0;
    KthLargest(int k, vector<int> &nums)
    {
        ind = k;
        for (int i : nums)
        {
            ms.insert(i);
        }
    }

    int add(int val)
    {
        ms.insert(val);
        auto itr = ms.end();
        int temp = ind;
        while (temp--)
        {
            itr--;
        }
        return *itr;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
