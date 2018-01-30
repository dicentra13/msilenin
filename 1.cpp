#include <iostream>
#include <vector>	

using namespace std;

vector<int> read() {
	size_t n;
	cin >> n;
	vector<int> v;
	v.resize(n + 1);
	for(size_t i = 0; i < n; i++) {
		cin >> v[i];
	}	
	return v;
}

size_t binary_search(vector<int>& v, int x) {
	size_t m, l = 0, r = v.size() - 1;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (x > v[m]) {
			l = m;
		}
		else if (x < v[m]) {
			r = m;
		}
		else {
			break;
		}
	}
	return l + 1;
}




int main() {
	vector<int> v = read();
	int x;
	cin >> x;
	size_t l = binary_search(v, x);
	v.insert(v.begin() + l, x);
	for (size_t i = 0; i < v.size() - 1; i++) {
		cout << v[i] << " ";
	}
	return 0;
}
