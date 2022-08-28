#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

bool startsWith(vector<char>& a, vector<char>& b) {
	for (int i = 0; i < (int)b.size(); i++) {
		if (a[i] != b.at(i)) return false;
	}
	return true;
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<char> sarr((int)s.size());
	for (int i = 0; i < (int)s.size(); i++) sarr[i] = s.at(i);

	vector<vector<char>> ans(n - 1);
	int ansI = 0;
	if (s.size() < 10) {
		vector<char> base(10);
		for (int i = 0; i < 10; i++) base[i] = '.';
		// make sure permutations of 10 don't begin with s
		for (int i = -1; i < 10 && ansI < n - 1; i++) {
			if (i > -1) base[i] = '-';
			vector<char> temp = base;
			do {
				if (!startsWith(temp, sarr)) {
					ans[ansI] = temp;
					ansI++;
				}
			} while (next_permutation(temp.begin(), temp.end()) && ansI < n - 1);
		}
	} else {
		// make sure no permutation of 10 matches the starting characters of s
		vector<char> base(10);
		for (int i = 0; i < 10; i++) base[i] = '.';
		for (int i = -1; i < 10 && ansI < n - 1; i++) {
			if (i > -1) base[i] = '-';
			vector<char> temp = base;
			do {
				if (!startsWith(sarr, temp)) {
					ans[ansI] = temp;
					ansI++;
				}
			} while (next_permutation(temp.begin(), temp.end()) && ansI < n - 1);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < 10; j++) cout << ans[i][j];
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ":\n";
		solve();
	}
	return 0;
}
