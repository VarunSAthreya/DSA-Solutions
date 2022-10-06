class TimeMap
{
    unordered_map<string, map<int, string>> m;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        m[key].insert({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto it = m[key].upper_bound(timestamp);

        return it == m[key].begin() ? "" : prev(it)->second;
    }
};

// * Using VECTOR as the add the timestamp in increasing order
class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto it = upper_bound(begin(m[key]), end(m[key]), pair<int, string>(timestamp, ""), [](const pair<int, string> &a, const pair<int, string> &b)
                              { return a.first < b.first; });

        return it == m[key].begin() ? "" : prev(it)->second;
    }
};
