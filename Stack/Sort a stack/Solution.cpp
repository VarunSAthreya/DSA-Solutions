/*The structure of the class is class SortedStack
{
public:
    stack<int> s;
    void sort();
};
* /

    /* The below method sorts the stack s
you are required to complete the below method */

void stackInsert(stack<int> &s, int x)
{
    if (s.size() == 0 || s.top() <= x)
    {
        s.push(x);
        return;
    }
    int val = s.top();
    s.pop();

    stackInsert(s, x);
    s.push(val);
}

void sortStack(stack<int> &s)
{
    if (s.size() <= 1)
        return;

    int x = s.top();
    s.pop();
    sortStack(s);
    stackInsert(s, x);
}

void SortedStack ::sort()
{
    //Your code here
    sortStack(s);
}
