#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

set<char> vow({'A', 'E', 'I', 'O', 'U'});
bool isVow(char c) {
	return vow.find(c) != vow.end();
}

void solve(int c) {
	string s;
	cin >> s;
	int n = (int)s.size();

	int minSecs = INT_MAX;
	for (int i = 0; i < 26; i++) {
		int secs = 0;
		for (int j = 0; j < n; j++) {
			if (s.at(j) - 'A' != i) {
				if (isVow(s.at(j)) != isVow(i + 'A')) secs += 1;
				else secs += 2;
			}
		}
		minSecs = min(minSecs, secs);
	}
	cout << "Case #" << c << ": " << minSecs << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}
