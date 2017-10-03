#include <iostream>
#include <algorithm>
#include <fstream>
#define MAX_K 100
using namespace std;
int choise_sort(int a[MAX_K], int n) {
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
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}




int bubble_sort(int a[MAX_K], int n) {
	for (int i = 0; i < n; i++) {
    	for (int j = i - 1; j >= 0; j--) {
      		if (a[j] > a[j + 1]) {
      			swap(a[j], a[j + 1]);
      		}
    	}
    }
	for(int i = 0; i < n; i++) {
		 cout << a[i] << " ";
	}
	cout << endl;
	return 0;

}




int insertion_sort(int a[MAX_K], int n) {
	int j;
    for (int i = 0; i < n; i++) {
    	j = i;
    	while (j > 0 && a[j - 1] < a[j]) {
    		swap(a[j], a[j - 1]);
    		j -= 1;
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
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
	choise_sort(a, n);
	bubble_sort(a, n);
	sort(a, n);
	fout.close();
	fin.close();
	system("pause");
	return 0;
}
