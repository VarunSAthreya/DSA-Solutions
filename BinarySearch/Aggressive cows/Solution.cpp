#include <bits/stdc++.h>

using namespace std;

#define nline "\n"
#define vi vector<int>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()

// Template end
bool isPossible(vi &vec, int mid, int c)
{
	int cnt = 1;
	int prev = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] - prev >= mid)
		{
			prev = vec[i];
			cnt++;
		}
		// OR:
		// if(cnt == c) return true;
	}
	//  return false;
	return cnt >= c;
}

void solve()
{
	int n, c;
	cin >> n >> c;
	vi vec(n);

	FOR(i, n)
	{
		cin >> vec[i];
	}

	sort(all(vec));

	int low = vec[0];
	int high = vec[n - 1];

	int res = -1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (isPossible(vec, mid, c))
		{
			low = mid + 1;
			res = mid;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << res << nline;
}

int main()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}
