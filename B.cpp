#include <iostream>
#include <vector>

using namespace std;

int main () {
	size_t n;
	cin >> n;
	vector<size_t> h;
	for (size_t i = 0; i < n; i++) {
		size_t t;
		cin >> t;
		h.push_back(t);
	}
	size_t max = h[0], a = 0, b = 0;  // max - ������������ �������, a, b - ������� �� max �� max ( ��������, � ��� 11 �������, �� ����� ��������, ������� ���������� �� 1 �������, �� ���� ��� ������ �� ������� ������� �� 10 ������� => a = 1, b = 10 ). � ����� ������� a = b �.�. ������� �� 9 ������ ������ ����.
	for (size_t i = 0; i < n; i++) {
		if (h[i] == max) {
			b = i;
		}
		if (h[i] > max) {
			a = i;
			b = i;
			max = h[i];
		}
	}
	size_t res = 0, max2 = 0; // res - ������������� �� �������� ���������, max2 - ������ ��������. ���� ��� �����. � ������ �� ������� �� ������ �� a ���-�� ������ ������. �� ������ �� ������� ������ ����� �� a �� b. � ������� �� ������� ����� �� b �� �����.
	for (size_t i = 0; i < a; i++) {
		if (h[i] > max2) {
			max2 = h[i];
		}
		res += max2 - h[i];
	}
	for (size_t i = a; i < b; i++) {
		res += max - h[i];
		max2 = 0;
	}
	for (size_t i = n - 1; i > b; i--) {
		if (h[i] > max2) {
			max2 = h[i];
		}
		res += max2 - h[i];
	}
	cout << res;
	return 0;
}
