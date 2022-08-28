#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve() {
	int n;
	string s;
	cin >> n >> s;
	// only works because first half of ans will never
	// equal second half due to low n
	vector<char> ans(200);
	for (int i = 0; i < 100; i++) ans[i] = '-';
	for (int i = 100; i < 200; i++) ans[i] = '.';
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < 200; j++) {
			cout << ans[j];
		}
		cout << "\n";
		next_permutation(ans.begin(), ans.end());
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
