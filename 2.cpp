#include <iostream>
#include <vector>

using namespace std;

int main() {
	double n;
	cin >> n;
	vector <double> v;
	for (double i = 0.0; i < n; i = i + 1.0) {
		v.push_back(1 / (i + 1));
		cout << v[i] << " ";
	}
	return 0;
}
