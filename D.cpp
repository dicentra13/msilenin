#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long n, k;
	cin >> n;
	k = sqrt(n);
	while (n % k != 0) {
		k--;
	}
	long long x = k, y = n / k, r;
	r = sqrt(x * x + y * y) / 2;
	cout << r + 1;
	return 0;
}
