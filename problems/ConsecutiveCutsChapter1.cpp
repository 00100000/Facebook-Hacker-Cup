#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++) {
		if (a[i] == b[0]) {
			bool valid = true;
			int j = 0;
			for (int l = i; l < n; j++, l++) {
				if (a[l] != b[j]) {
					valid = false;
					break;
				}
			}
			for (int l = 0; l < i; j++, l++) {
				if (a[l] != b[j]) {
					valid = false;
					break;
				}
			}
			if (valid) {
				if (i == 0) {
					if (k == 0) {
						cout << "YES";
					} else if ((n == 2 && k % 2 == 1) || k == 1) {
						cout << "NO";
					} else {
						cout << "YES";
					}
				} else if (i == n - 1) {
					if ((n == 2 && k % 2 == 0) || k == 0) {
						cout << "NO";
					} else {
						cout << "YES";
					}
				} else {
					if (k == 0) {
						cout << "NO";
					} else {
						cout << "YES";
					}
				}
			} else {
				cout << "NO";
			}
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
