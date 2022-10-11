#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int r, c;
vector<vector<char>> grid;
vector<vector<int>> neighbors;

void ff(int x, int y) {
	if (grid[x][y] != '^') return;
	if (x < 0 || x > r - 1 || y < 0 || y > c - 1) return;
	if (neighbors[x][y] < 2) {
		grid[x][y] = '.';
		if (x + 1 < r) {
			neighbors[x + 1][y]--;
			ff(x + 1, y);
		}
		if (x - 1 >= 0) {
			neighbors[x - 1][y]--;
			ff(x - 1, y);
		}
		if (y + 1 < c) {
			neighbors[x][y + 1]--;
			ff(x, y + 1);
		}
		if (y - 1 >= 0) {
			neighbors[x][y - 1]--;
			ff(x, y - 1);
		}
	}
}

void solve() {
	cin >> r >> c;
	grid.clear();
	grid.resize(r, vector<char>(c));
	int treecnt = 0;
	for (int i = 0; i < r; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < c; j++) {
			if (temp.at(j) == '^') treecnt++;
			grid[i][j] = temp.at(j);
		}
	}
	if (treecnt == 0) {
		cout << "Possible\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << grid[i][j];
			}
			cout << "\n";
		}
	} else if (r < 2 || c < 2) {
		cout << "Impossible\n";
	} else {
		vector<vector<char>> original = grid;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == '.') {
					grid[i][j] = '^';
				}
			}
		}
		neighbors.clear();
		neighbors.resize(r, vector<int>(c));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i + 1 < r) if (grid[i + 1][j] == '^') neighbors[i][j]++;
				if (i - 1 >= 0) if (grid[i - 1][j] == '^') neighbors[i][j]++;
				if (j + 1 < c) if (grid[i][j + 1] == '^') neighbors[i][j]++;
				if (j - 1 >= 0) if (grid[i][j - 1] == '^') neighbors[i][j]++;
			}
		}
		// floodfill to remove invalid trees
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ff(i, j);
			}
		}
		// check that no original trees have been removed
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (original[i][j] == '^' && grid[i][j] != '^') {
					cout << "Impossible\n";
					return;
				}
			}
		}

		cout << "Possible\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << grid[i][j];
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
