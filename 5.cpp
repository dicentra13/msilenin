#include <iostream>
#include <vector>

using namespace std;

int main() {
	size_t n;
	cin >> n;
	vector <int> a, b;
	for (size_t i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
		int s = 0;
		for (size_t j = 0; j <= i; j++) {
			s += a[j];
		}
		b.push_back(s);
		cout << b[i] << " ";
	}
	return 0;
}
