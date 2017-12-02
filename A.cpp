#include <iostream>

using namespace std;

int main() {
	long long k, p, res = 0, ost = 0;
	cin >> k >> p;
	ost = p % k;
	if (ost <= k / 2) {
		res = p - ost;
	}
	else {
		res = p + (k - ost);
	}
	cout << res;
	return 0;
}
