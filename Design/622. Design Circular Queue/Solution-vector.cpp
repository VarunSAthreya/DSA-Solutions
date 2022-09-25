class MyCircularQueue
{
public:
    vector<int> q;
    int n;

    MyCircularQueue(int k)
    {
        n = k;
    }

    bool enQueue(int value)
    {
        if (q.size() < n)
        {
            q.push_back(value);
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        if (q.size())
        {
            q.erase(q.begin());
            return true;
        }
        return false;
    }

    int Front()
    {
        if (q.size() == 0)
            return -1;
        return q[0];
    }

    int Rear()
    {
        if (q.size() == 0)
            return -1;
        return q[q.size() - 1];
    }

    bool isEmpty()
    {
        return q.size() == 0;
    }

    bool isFull()
    {
        return q.size() == n;
    }
};
