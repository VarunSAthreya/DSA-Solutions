#include<bits/stdc++.h>

using namespace std;
#define nline           "\n"

void solve() {
	int n, m;
	cin >> n >> m;
	n--, m--;
    
	if (n == 0 && m == 0) cout << 0 << nline;
	else cout << min(n, m) * 2 + max(n, m) + 1 << nline;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}