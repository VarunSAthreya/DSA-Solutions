#include<bits/stdc++.h>

using namespace std;

#define FOR(i,n)		for(int i =0;i<n;i++)

void solve() {
	int num, div, n;
	cin >> num >> div >> n;

	FOR(i, 10) {
		int tmp = num * 10 + i;
		if ( tmp % div == 0) {
			string s(n - 1, '0');
			cout << tmp << s;
			return;
		}
	}

	cout << -1;
}

int main() {
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}