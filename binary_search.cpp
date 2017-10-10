#include <iostream>
#include <fstream>	
#define MAX_K 100	

using namespace std;

void  binary_search(int *a, int key, int r, ostream& out) {
	int m, l = 0;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (key > a[m]) {
			l = m;
		}
		else if (key < a[m]) {
			r = m;
		}
		else {
			break;
		}
	}
	out << m;
}




int main() {
	ifstream fin;
	ofstream fout;
	fin.open("in.txt");
	fout.open("out.txt");
	int a[MAX_K], n, key;
	fin >> n >> key;
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}
	binary_search(a, key, n, fout);
	return 0;
}
