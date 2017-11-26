#include <iostream>
#include <fstream>

using namespace std;

size_t min (size_t a, size_t b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("calc.in");
	fout.open("calc.out");
	long long n;
	size_t a, b, c;
	fin >> n >> a >> b >> c;
	size_t arr[a][b][c];
	arr[0][0][0] = n;
	for (size_t i = 0; i <= a; i++) {
		for (size_t j = 0; j <= b; j++) {
			for (size_t k = 0; k <= c; k++) {
				if (i < a) {
					arr[i + 1][j][k] = arr[i][j][k] / 2;
				}
				if (j < b) {
					arr[i][j + 1][k] = (arr[i][j][k] + 1) / 2;
				}
				if (k < c) {
					arr[i][j][k + 1] = (arr[i][j][k] - 1) / 2;
				}
			}
		}
	} 
	fout << arr[a][b][c];
	fin.close();
	fout. close();
	return 0;
}
