#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX_Q 1000

using namespace std;


int main() {
	ifstream fin;
	ofstream fout;
	fin.open("building.in");
	fout.open("building.out");
	long long n, k, x, y, a[MAX_Q];
	fin >> n >> k >> x >> y;
	size_t q;
	fin >> q;
	if (x == y) {
		for (size_t i = 0; i < q; i++) {
			fin >> a[i];
			long long res = a[i] / y;
			fout << res << endl;
		}
		fout.close();
		fin.close();
		return 0;
	}
	long long p = (n / k) * x + (n - n / k) * y;
	long long b = x + (k - 1) * y;
	for (size_t i = 0; i < q; i++) {
		fin >> a[i];
		a[i] = (a[i] - 1) % p;
		long long res = a[i] / b * k + min((a[i] % b) / y, k - 1) + 1;
		fout << res << endl;
	}
	return 0;
}
