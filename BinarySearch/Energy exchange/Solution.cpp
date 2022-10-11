#include <bits/stdc++.h>

using namespace std;

#define nline "\n"
typedef long long ll;
typedef long double lld;
void precision(int a) { cout << setprecision(a) << fixed; }

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<lld> a(n);
    for (auto &i : a)
        cin >> i;

    precision(9);

    lld l = 0, r = 1e10;

    while (r - l > 0.0000000001) // as precision is upto 9 digits
    {
        lld mid = l + (r - l) / 2.0;
        lld energy = 0;

        for (int i : a)
        {
            if (i > mid)
            {
                energy += (i - mid) * (1.0 - (k * 1.0 / 100.0));
            }
            else
            {
                energy -= (mid - i);
            }
        }

        if (energy > 0.0)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << r << nline;

    return 0;
}
