/* 
    * Create a Segment tree which store the values of the range
    * While building the tree we need to use `OR` and `XOR` operations alternatively
    * The first operation of `OR` and `XOR` depends on the power of 2 of the range i.e n in 2^n
    * If the power of 2 is odd then the first operation is `OR` and if the power of 2 is even then the first operation is `XOR`
    * For queries update the values for the given index and then the parent values also updates
    * Return the value of the root node
*/ 

#include<bits/stdc++.h>
using namespace std;

#define nline           "\n"

class SegmentTree {
	vector<int> seg;
public:
	SegmentTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(vector<int> &nums, int low, int high, int ind, bool isOr) {
		if (low == high) {seg[ind] = nums[low]; return;}

		int mid = low + (high - low) / 2;

		build(nums, low, mid, 2 * ind + 1, !isOr);
		build(nums, mid + 1, high, 2 * ind + 2, !isOr);

		if (isOr)seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
		else seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
	}

	void update(int i, int val, int low, int high, int ind, bool isOr) {
		if (low == high) {seg[ind] = val; return;}

		int mid = low + (high - low) / 2;

		if (i <= mid) update(i, val, low, mid, 2 * ind + 1, !isOr);
		else update(i, val, mid + 1, high, 2 * ind + 2, !isOr);

		if (isOr)seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
		else seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
	}

	int top() {return seg[0];}
};

void solve() {
	int n, q;
	cin >> n >> q;
	int size = pow(2, n);

	vector<int> nums(size);
	for (auto &i : nums) cin >> i;

	SegmentTree *t = new SegmentTree(size);

	if (n % 2 == 0) t->build(nums, 0, size - 1, 0, false);
	else t->build(nums, 0, size - 1, 0, true);

	while (q--) {
		int i, val;
		cin >> i >> val;
		i--;

		if (n % 2 == 0) t->update(i, val, 0, size - 1, 0, false);
		else t->update(i, val, 0, size - 1, 0, true);

		cout << t->top() << nline;
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