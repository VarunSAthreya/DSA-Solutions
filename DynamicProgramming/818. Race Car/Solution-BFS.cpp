class Solution
{
public:
    int racecar(int target)
    {
        queue<vector<double>> q;
        set<pair<double, double>> visited;

        q.push({0, 0, 1});

        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            double moves = v[0], position = v[1], speed = v[2];

            if (position == target)
                return (int)moves;

            if (visited.count({position, speed}))
                continue;
            else
                visited.insert({position, speed});

            q.push({moves + 1, position + speed, speed * 2});

            if ((position + speed > target && speed > 0) || position + speed < target && speed < 0)
            {
                speed = speed < 0 ? 1 : -1;
                q.push({moves + 1, position, speed});
            }
        }

        return -1;
    }
};
