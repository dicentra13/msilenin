#include <iostream>
#include <vector>

using namespace std;

int main() {
	size_t n;
	cin >> n;
	vector <int> v;
	for (size_t i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.insert(v.begin(), t);
	}
	for (size_t i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	/*
	for (size_t i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	for (size_t i = n - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
	*/
	return 0;
}
