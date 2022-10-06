#include<bits/stdc++.h>

using namespace std;

#define nline           "\n"
typedef long long int lli;

lli subarray(vector<int> &v) {
	lli curr = 0, res = INT_MIN;

	for (int i : v) {
		curr += i;
		res = max(curr, res);
		if (curr < 0) curr = 0;
	}

	return res;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;

	int m; cin >> m;
	vector<int> b(m);
	lli pos = 0;
	for (auto &i : b) {cin >> i; if (i > 0) pos += i;} // sum of positive elements

	a.push_back(pos); // add positive sum to the back of the array 
	lli back = subarray(a);

	a.pop_back();
	a.insert(a.begin(), pos); // add positive sum to the front of the array
	lli front = subarray(a);

	cout << max(front, back) << nline;
}

int main() {

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
