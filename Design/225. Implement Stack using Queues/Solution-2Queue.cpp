class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        int cnt = 0;
        int res;
        while (!q1.empty())
        {
            q2.push(q1.front());
            res = q1.front();
            q1.pop();
            cnt++;
        }
        for (int i = 0; i < cnt - 1; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();

        return res;
    }

    int top()
    {
        int res;
        while (!q1.empty())
        {
            q2.push(q1.front());
            res = q1.front();
            q1.pop();
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        return res;
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};
