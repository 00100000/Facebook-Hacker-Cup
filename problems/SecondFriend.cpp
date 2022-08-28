#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve() {
	int r, c;
	cin >> r >> c;
	vector<vector<bool>> grid(r, vector<bool>(c));
	int treecnt = 0;
	for (int i = 0; i < r; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < c; j++) {
			if (temp.at(j) == '^') {
				treecnt++;
				grid[i][j] = true;
			}
		}
	}
	if (treecnt == 0) {
		cout << "Possible\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << '.';
			}
			cout << "\n";
		}
	} else if (r < 2 || c < 2) {
		cout << "Impossible\n";
	} else {
		cout << "Possible\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << '^';
			}
			cout << "\n";
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
	}
	return 0;
}
