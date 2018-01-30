#include <iostream>
#include <vector>

using namespace std;

vector<int> read() {
	size_t n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (size_t i = 0; i < n; i++) {
		cin >> v[i];
	}
	return v;
}

void cyclic_shift(vector<int>& v) {
	int k = v[v.size() - 1];
	for(int i = v.size() - 1; i >= 0; i--) {
		v[i] = v[i - 1];
	}
	v[0] = k;
}

int main() {
	vector<int> v = read();
	size_t pos;
	cin >> pos;
	for (size_t i = 0; i < v.size() - pos; i++) {
		cyclic_shift(v);
	}
	for (size_t i = 0;  i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}
