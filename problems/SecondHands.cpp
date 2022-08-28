#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve(int c) {
	int n, k;
	cin >> n >> k;
	vector<int> freq(100);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		temp--;
		freq[temp]++;
	}
	int one = 0, two = 0;
	for (int i = 0; i < 100; i++) {
		if (freq[i] == 1) one++;
		if (freq[i] == 2) two++;
		if (freq[i] > 2) {
			cout << "Case #" << c << ": " << "NO\n";
			return;
		}
	}

	cout << "Case #" << c << ": " << ((k - two) * 2 >= one ? "YES" : "NO") << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}
