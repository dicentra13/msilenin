#include <iostream>
#include <algorithm>
#include <fstream>
#define MAX_K 100
using namespace std;
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("in.txt");
	fout.open("out.txt");
	int a[MAX_K], N;
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> a[i];
	}
	int pos;
    for (int i = 0; i < N; i++) {        //Comment
    	pos = i;
    	for(int j = i + 1; j < N; j++) { //Comment 2
    		if(a[pos] > a[j]) {
    			pos = j;
			}
		}
		swap(a[pos], a[i]);
	}
	for(int i = 0; i < N; i++) {
		fout << a[i] << " ";
	}
	fout.close();
	return 0;
}
