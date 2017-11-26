#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_N 10000

using namespace std;

int main() {
	size_t n;
	cin >> n;
	int a[MAX_N];
	if ( n == 2 ) {
		cin >> a[0] >> a[1];
		cout << a[0] * a[1];
		return 0;
	}
	else if ( n == 3 ) {
		cin >> a[0] >> a[1] >> a[2];
		int max = a[0];
		int min = a[1];
		if (min > max) {
			swap(min, max);
		}
		int min2 = a[2];
		if (min2 > max) {
			swap(max, min2);
		}
		else if (min2 < min) {
			swap(min, min2);
		}
		if (min < 0 && max < 0) {
			cout << max * min2;
			return 0;
		}
		else if (min < 0 && max > 0) {
			cout << min * max;
			return 0;
		}
		else {
			cout << min * min2;
			return 0;
		}
	}
	else {
		int max, max2, min, min2;
		cin >> a[0];
		max = a[0];
		cin >> a[1];
		max2 = a[1];
		if (max < max2) {
			swap(max, max2);
		}
		cin >> a[2];
		min = a[2];
		if (min > max) {
			swap(max, min);
		}
		else if (min > max2) {
			swap(min, max2);
		}
		cin >> a[3];
		min2 = a[3];
		if (min2 < min) {
			swap(min, min2);
		}
		else if (min2 > max) {
			swap(min2, max);
			swap(min2, max2);
		}
		else if (min2 > max2) {
			swap(min2, max2);
		}
		for ( int i = 4; i < n; i++ ) {
			cin >> a[i];
			if (a[i] > max) {
				max2 = max;
				max = a[i];
			}
			else if (a[i] > max2) {
				max2 = a[i];
			}
			else if(a[i] < min){
				min2 = min;
				min = a[i];
			}
			else if (a[i] < min2) {
				min2 = a[i];
			}
		}
		if (min < 0 && max < 0) {
			cout << max * min2;
			return 0;
		}
		else if (min < 0 && max > 0) {
			cout << min * max;
			return 0;
		}
		else {
			cout << min * min2;
			return 0;
		}
	}
}
