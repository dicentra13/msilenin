#include <iostream>
#include <vector>

using namespace std;

int main() {
	size_t n;
	cin >> n;
	vector <size_t> h, l, r;
	h.resize(n);
	l.resize(n);
	r.resize(n);
	for (size_t i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (size_t i = 0; i < n; i++) {
		l[i] = i;
		if (i > 0 && l[i - 1] > i - h[i] + 1) {
			l[i] = i - h[i] + 1;
		}
		else if (i > 0 && h[i] > 1) {
			l[i] = l[i - 1];
		}
		cout << l[i] << " ";
	}
	cout << endl;
	for (int i = n - 1; i >= 0; i--) {
		r[i] = i;
		if (i < n - 1 && r[i + 1] < i + h[i] - 1) {
			r[i] = i + h[i] - 1;
		}
		else if(i < n - 1 && h[i] > 1) {
			r[i] = r[i + 1];
		}
		cout << r[i] << " ";
	}
	return 0;
}
