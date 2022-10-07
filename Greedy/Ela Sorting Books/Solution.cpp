#include<bits/stdc++.h>

using namespace std;
#define nline           "\n"


void solve() {
	int n, k, m; cin >> n >> m;
	string s; cin >> s;

	string res = "";
	vector<int> freq(26, 0);
	for (auto ch : s) freq[ch - 'a']++;

	k = m;
	int window = min(n / m, 26);
	while (k--) {
		int flag = 1;
		int ind = 0;
		while (ind < window) {
			if (freq[ind] == 0) {
				flag = 0;
				break;
			}

			freq[ind]--;
			ind++;
		}

		if (flag) res += ('a' + n / m);
		else res += ('a' + ind);
	}

	cout << res << nline;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
