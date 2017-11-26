#include <iostream>

using namespace std;

int main () {
	int hd, md, hf, mf, d, a, x, days;
	x = (((hd - d) * 60 + md) + hf * 60 + mf) + a * 60
	/*
	(hd - d) time on UTC 0  
	((hd - d) * 60 + md) time on UTC 0 in minutes
	(hf * 60 + mf) flight time in minutes
	(a * 60) UTC of arrival in minutes
	x arrival time in minutes
	*/
	days = x / 24 * 60;
	x %= 24 * 60;   // arrival time in minutes without days
	cout << x / 60 << " " << x % 60 << " " << days;
	/*
	(x / 60) hours of arrival time
	(x % 60) minutes of arrival time 
	*/
	return 0;
}
