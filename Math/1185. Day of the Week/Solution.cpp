class Solution
{
public:
    bool leap(int y)
    {
        if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
            return 1;
        return 0;
    }

    int find(int d, int m, int y)
    {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int c = 0;
        // take any base year less than all the inputs
        int my = 1940;

        while (my < y)
        {
            if (leap(my))
                c += 366;
            else
                c += 365;
            my++;
        }

        // cout << c << " ";
        if (leap(y))
            days[1] += 1;
        for (int i = 0; i < m - 1; i++)
        {
            c += days[i];
        }
        c += d;
        return c;
    }
    string dayOfTheWeek(int d, int m, int y)
    {

        // start from today's day (i.e I have taken 28/10/2020 , so on 28/10/2020 Wednesday, hence start from here
        // you can take any date and corresponding day
        vector<string> day = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};

        int c1 = find(28, 10, 2020);
        int c2 = find(d, m, y);

        int dif = (c2 - c1) % 7;
        if (dif < 0)
            dif += 7;
        return day[dif];
    }
};
