#include <iostream>
#include <vector>

using namespace std;

int main () {
	size_t n;
	cin >> n;
	vector<size_t> h(n, 0);
	for (size_t i = 0; i < n; i++) {
		cin >> h[i];
	}
	size_t max = h[0], a = 0, b = 0;  // max - максимальный столбец, a, b - отрезок от max до max ( например, у нас 11 стобцов, мы нашли максимум, который находитьс€ на 1 позиции, но есть еще такого же размера столбец на 10 позиции => a = 1, b = 10 ). ¬ нашем примере a = b т.к. столбец из 9 блоков только один.
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
	size_t res = 0, max2 = 0; // res - соответсвенно по названию результат, max2 - второй максимум. Ќиже три цикла. ¬ первом мы считаем от начала до a кол-во водных блоков. ¬о втором мы считаем водные блоки от a до b. ¬ третьем мы считаем блоки от b до конца.
	for (size_t i = 0; i < a; i++) {
		if (h[i] > max2) {
			max2 = h[i];
		}
		res += max2 - h[i];
	}
	for (size_t i = a; i < b; i++) {
		res += max - h[i];
	}
	max2 = 0;
	for (size_t i = n - 1; i > b; i--) {
		if (h[i] > max2) {
			max2 = h[i];
		}
		res += max2 - h[i];
	}
	cout << res;
	return 0;
}
