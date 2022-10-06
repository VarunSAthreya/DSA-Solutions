#include<bits/stdc++.h>

using namespace std;
#define nline           "\n"

class ST {
	vector<int> seg, lazy;
public:
	ST(int n) {
		seg.resize(4 * n);
		lazy.resize(4 * n);
	}

	void build(int ind, int low, int high, vector<int> &arr) {
		if (low == high) {
			seg[ind] = (arr[low] == 1); // if head then 1 else 0
			return;
		}
		int mid = (low + high) >> 1;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}

	void update(int ind, int low, int high, int l, int r) {
		// update the previous remaining updates
		// and propogate downwards
		if (lazy[ind] != 0) {
			seg[ind] = (high - low + 1) - seg[ind]; // flip the segment
			// propogate the lazy update downwards
			// for the remaining nodes to get updated
			if (low != high) {
				lazy[2 * ind + 1] = !lazy[2 * ind + 1]; // flip the lazy update
				lazy[2 * ind + 2] = !lazy[2 * ind + 2]; // flip the lazy update
			}

			lazy[ind] = 0;
		}

		// no overlap
		// we don't do anything and return
		// low high l r or l r low high
		if (high < l or r < low) {
			return;
		}

		// complete overlap
		// l low high r
		if (low >= l && high <= r) {
			seg[ind] = (high - low + 1) - seg[ind]; // flip the segment
			// if a leaf node, it will have childrens
			if (low != high) {
				lazy[2 * ind + 1] = !lazy[2 * ind + 1]; // flip the lazy update
				lazy[2 * ind + 2] = !lazy[2 * ind + 2]; // flip the lazy update
			}
			return;
		}
		// last case has to be no overlap case
		int mid = (low + high) >> 1;
		update(2 * ind + 1, low, mid, l, r);
		update(2 * ind + 2, mid + 1, high, l, r);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2]; // update the current node, add heads from left and right
	}

	int query(int ind, int low, int high, int l, int r) {

		// update if any updates are remaining
		// as the node will stay fresh and updated
		if (lazy[ind] != 0) {
			seg[ind] = (high - low + 1) - seg[ind]; // flip the segment
			// propogate the lazy update downwards
			// for the remaining nodes to get updated
			if (low != high) {
				lazy[2 * ind + 1] = !lazy[2 * ind + 1]; // flip the lazy update
				lazy[2 * ind + 2] = !lazy[2 * ind + 2]; // flip the lazy update
			}

			lazy[ind] = 0;
		}

		// no overlap return 0;
		if (high < l or r < low) {
			return 0;
		}

		// complete overlap
		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
        
		return left + right;
	}
};


void solve() {
	int n, q; cin >> n >> q;

	vector<int> coins(n);
	for (auto &i : coins) i = 0; // all coins are initially tails

	ST st(n);
	st.build(0, 0, n - 1, coins);

	while (q--) {
		int type; cin >> type;

		if (type) {
			int l, r; cin >> l >> r;
			cout << st.query(0, 0, n - 1, l, r) << nline;
		} else  {
			int l, r; cin >> l >> r;
			st.update(0, 0, n - 1, l, r);
		}
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
