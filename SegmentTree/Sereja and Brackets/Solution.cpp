#include<bits/stdc++.h>

using namespace std;
#define nline           "\n"

struct Node {
	int full = 0, open = 0, close = 0;
};

class SegmentTree {
	vector<Node> seg;

public:
	SegmentTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high, string &s) {
		if (low == high) {
			if (s[low] == '(') seg[ind].open++;
			else if (s[low] == ')') seg[ind].close++;

			return;
		}

		int mid = (low + high) / 2ll;
		build(2 * ind + 1, low, mid, s);
		build(2 * ind + 2, mid + 1, high, s);

		seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
	}

	Node query(int ind , int low, int high, int l, int r) {
		// No overlap
		if (r < low || l > high) {Node temp; return temp;}

		// Complete Overlap
		if (low >= l and r >= high) return seg[ind];

		// Partially Overlap
		int mid = (low + high) >> 1ll;
		Node left = query(2 * ind + 1, low, mid, l, r);
		Node right = query(2 * ind + 2, mid + 1, high, l, r);

		return merge(left, right);
	}

	Node merge(Node &left, Node &right) {
		Node temp;

		temp.full = left.full + right.full + min(left.open, right.close);
		temp.open = left.open + right.open - min(left.open, right.close);
		temp.close = left.close + right.close - min(left.open, right.close);

		return temp;
	}
};
void solve() {
	string s; cin >> s;
	int n = s.length();
	SegmentTree sg(n);

	sg.build(0, 0, n - 1, s);

	int m; cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		l--; r--;

		Node res = sg.query(0, 0, n - 1, l, r);

		cout << res.full * 2 << nline;
	}
}

int main() {
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}