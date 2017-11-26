#include <iostream>
#include <vector>

using namespace std;

int main() {
	size_t n;
	cin >> n;
	vector <size_t> v;
	for (size_t i = 0; i < n; i++) {
		v.push_back((i + 1) * (i + 1));
		cout << v[i] << " "; 
	}
	return 0;
}
