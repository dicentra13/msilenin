#include <iostream>	
#include <fstream>
#define MAX_K 100

using namespace std;




void print_array(int* a, size_t n, ostream& out) {
	for (size_t i = 0; i < n; ++i) {
			out << a[i] << " ";
	}
	out << endl;
}




void counting_sort(int *a, size_t n, ostream& out) {
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (min > a[i]) {
			min = a[i];
	    }
	}
	for (int i = 0; i < n; i++) {
		a[i] -= min;
    }
    int max = a[0];
    for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
	    }
	}
	int count[max + 1];
	for (int i = 0; i < max + 1; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		count[a[i]] += 1;
	}
	int res[n];
	for (int i = 0; i < n; i++) {
		res[i] = 0;
	}
	int ind = 0;
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < count[i]; j++) {
			res[ind] = i;
			ind += 1;
		}
	}
	for (int i = 0; i < n; i++){
		res[i] += min;
	}
	print_array(res, n, out);
}




int main() {
	ifstream fin;
	ofstream fout;
	fin.open("in.txt");
	fout.open("out.txt");
	int a[MAX_K], n;
	fin >> n;;
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}
	counting_sort(a, n, fout);
	fout.close();
	fin.close();
	return 0;
}
