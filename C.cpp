#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	size_t n, m;
	cin >> n >> m;
	string a[n][m];
	int b[n][m][4];
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			if (a[i][j] == "W") {
				b[i][j][0] = 0;
				b[i][j][1] = 0;
			}
			else if (a[i][j] == ".") {
				if (j - 1 == -1 || b[i][j - 1][0] == 0) {
					b[i][j][0] = 1;
				}
				else {
					b[i][j][0] = b[i][j - 1][0];
				}
				if (i - 1 == -1 || b[i - 1][j][1] == 0) {
					b[i][j][1] = 1;
				}
				else {
					b[i][j][1] = b[i - 1][j][1];
				}
			}
			else {
				if (j - 1 == -1 || b[i][j - 1][0]) {
					b[i][j][0] = -1;
				}
				else {
					b[i][j][0] = -1 + b[i][j - 1][0];
				}
				if (i - 1 == -1 || b[i - 1][j][1] == 1) {
					b[i][j][1] = -1;
				}
				else {
					b[i][j][1] = -1 + b[i - 1][j][1];
				}
			}
		}
	}
	for (size_t i = n - 1; i >= 0; i--) {
		for (size_t j = m - 1; j >= 0; j--) {
			if (a[i][j] == "W") {
				b[i][j][2] = 0;
				b[i][j][3] = 0;
			}
			else if (a[i][j] == ".") {
				if (j + 1 == m || b[i][j + 1][2] == 0) {
					b[i][j][2] = 1;
				}
				else {
					b[i][j][2] = b[i][j + 1][2];
				}
				if (i + 1 == n || b[i + 1][j][3] == 0) {
					b[i][j][3] = 1;
				}
				else {
					b[i][j][3] = b[i + 1][j][3];
				}
			}
			else {
				if (j + 1 == m || b[i][j + 1][2]) {
					b[i][j][2] = -1;
				}
				else {
					b[i][j][2] = -1 + b[i][j + 1][2];
				}
				if (i + 1 == n || b[i + 1][j][3] == 1) {
					b[i][j][3] = -1;
				}
				else {
					b[i][j][3] = -1 + b[i + 1][j][3];
				}
			}
		}
	}
	size_t max = 0, ind1 = 0, ind2 = 0;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			if (a[i][j] == "." && max < abs(b[i][j - 1][0] + b[i - 1][j][1] + b[i][j + 1][2] + b[i + 1][j][3])) {
				max = abs(b[i][j - 1][0] + b[i - 1][j][1] + b[i][j + 1][2] + b[i + 1][j][3]);
				ind1 = i;
				ind2 = j;
			}
		}
	}
	cout << ind1 << " " << ind2;
	return 0;
}
