#include <iostream>
#include <vector>

using namespace std;

int main() {
	size_t n, k = 0;
	cin >> n;
	vector <int> a, b;
	for (size_t i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
		if (a[i - 1] != t && i != 0) {
			b.push_back(a[i - 1]);
			k += 1;
		}
		if (i == n - 1) {
			b.push_back(t);
			k += 1;
		}
	}
	for (size_t i = 0; i < k; i++) {
		cout << b[i] << " ";
	}
	return 0;
}
