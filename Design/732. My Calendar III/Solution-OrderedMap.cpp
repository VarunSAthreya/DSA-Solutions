class MyCalendarThree
{
    map<int, int> m;

public:
    MyCalendarThree() {}

    int book(int start, int end)
    {
        m[start]++;
        m[end]--;

        int curr = 0, res = 0;
        for (auto [k, v] : m)
        {
            curr += v;
            res = max(res, curr);
        }

        return res;
    }
};
