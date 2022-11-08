class StockSpanner
{
    stack<pair<int, int>> st; // [{price, count}] // count: the number of consecutive days (including the current day) for which the price of the stock was less than or equal to today's price.
public:
    StockSpanner() {}

    int next(int price)
    {
        int res = 1;

        while (st.size() && st.top().first <= price)
        {
            res += st.top().second;
            st.pop();
        }

        st.push({price, res});
        return res;
    }
};
