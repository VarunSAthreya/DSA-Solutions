#include<bits/stdc++.h>

using namespace std;

#define nline           "\n"
#define vi              vector<int>
#define sz(a)           a.size()

struct dsu {
	vi p, r;
	dsu(int n) : p(n), r(n) {
		for (int i = 1; i < n; ++i)
			p[i] = i;
	}
	int fs(int x) {
		if (x == p[x])
			return x;
		return p[x] = fs(p[x]);
	}
	void unite(int x, int y) {
		x = fs(x);
		y = fs(y);
		if (x == y)
			return;
		if (r[x] < r[y])
			swap(x, y);
		p[y] = x;
		if (r[x] == r[y])
			++r[x];
	}
};
const int C = 26;
void solve() {
	int n;
	cin >> n;
	int components = C;
	dsu d(C);
	string t;
	cin >> t;

	vi nx(C, -1), pr(C, -1);

	for (int i = 0; i < sz(t); ++i) {
		int I = t[i] - 'a';

		if (nx[I] == -1) {
			int j;
			for (j = 0; j < C; ++j) {
				if (j != I && pr[j] == -1) {
					if (components == 1 || d.fs(I) != d.fs(j)) {
						--components;
						nx[I] = j;
						pr[j] = I;
						d.unite(I, j);
						break;
					}
				}
			}
		}

		cout << char(nx[I] + 'a');
	}
	cout << nline;
}

int main() {

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
