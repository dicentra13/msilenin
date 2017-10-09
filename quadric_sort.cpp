#include <iostream>
#include <algorithm>
#include <fstream>
#define MAX_K 100

using namespace std;




void print_array(int* a, size_t n, ostream& out) {
	for (size_t i = 0; i < n; ++i) {
			out << a[i] << " ";
	}
	out << endl;
}




void choise_sort(int* a, size_t n, ostream& out) {
	int pos;
    for (int i = 0; i < n; i++) {
    	pos = i;
    	for(int j = i + 1; j < n; j++) {
    		if(a[pos] > a[j]) {
    			pos = j;
			}
		}
		swap(a[pos], a[i]);
	}
	print_array(a, n, out);
}




void bubble_sort(int* a, size_t n, ostream& out) {
	for (int i = 0; i < n; i++) {
    	for (int j = i - 1; j >= 0; j--) {
      		if (a[j] > a[j + 1]) {
      			swap(a[j], a[j + 1]);
      		}
    	}
    }
    print_array(a, n, out);
}




void insertion_sort(int* a, size_t n, ostream& out) {
	int j;
    for (int i = 0; i < n; i++) {
    	j = i;
    	while (j > 0 && a[j - 1] > a[j]) {
    		swap(a[j], a[j - 1]);
    		--j;
		}
	}
	print_array(a, n, out);
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
	choise_sort(a, n, fout);
	bubble_sort(a, n, fout);
	insertion_sort(a, n, fout);
	fout.close();
	fin.close();
	return 0;
}
