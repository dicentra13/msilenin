#include <iostream>	
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	long Rmin = max(abs(a), abs(b)) + max(abs(c), abs(d));
	for (int x = -10000; x <= 10000; x++) {
		for (int y = -10000; y <= 10000; y++) {
			long r = max(abs(x), abs(y)) + max(abs(a-x), abs(b - y)) + max(abs(c - x), abs(d - y));
			Rmin = min(Rmin, r);
		}
	}
	cout << Rmin;
}
