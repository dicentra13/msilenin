#include <iostream>
#include <cctype>

#define MAX_N 100

using namespace std;

size_t read_digits(int* digits)
{
    size_t n = 0;
    int c = cin.get();
    while (isdigit(c)) {
        digits[n] = c - '0';
        ++n;
        c = cin.get();
    }
    return n;
}




int calc_mod(int* digits, size_t n)
{
    int mod = 0;
    
    for (size_t i = 0; i < n; ++i) {
        mod = (mod + digits[i]) % 3;
    }
    
    return mod;
}




int max_inc(int digit, int mod)
{
	if ( digit == 9 ) {
		return 0;
	}
	size_t k = 0;
    if (mod == 0) {
		if ( digit < 7) {
			while (digit + 3 < 10) {
				k += 3;
				digit += 3;
			}
	    } 
		else {
			return 0;
		} 
	}
	else if (mod == 2) {
		while (digit + 3 < 9) {
			k += 3;
			digit += 3;
		}
		k += 1;
		digit += 1;
	}
	else {
		if (digit < 8) {
			while (digit + 3 < 8) {
				digit += 3;
				k += 3;
			}
			digit += 2;
			k += 2;
		}
		else {
			return 0;
		}
	}
	return k;
}




int min_dec(int digit, int mod)
{
	if ( digit == 1 ) {
		return 0;
	}
	size_t k;
	if ( mod == 0 ) {
		if ( digit  > 3 ) {
			k = 3;
		}
		else {
			return 0;
		}
	}
	else if ( mod == 1 ) {
		if ( digit > 2)	{
			k = 2;
		}
		else {
			return 0;
		}	
	}
	else {
		if ( digit > 1 ) {
			k = 1;
		}
		else {
			return 0;
		}
	}
	return k;
}




void print_digits(int* digits, size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        cout << digits[i];
    }
    cout << "\n";
}




int main()
{
    int digits[MAX_N];
    
    size_t n = read_digits(digits);
    int mod = calc_mod(digits, n);   
    
    size_t min_dec_index;
    int min_dec_val;
    
    size_t i = 0;
    for ( ; i < n; ++i) {
        int max_inc_val = max_inc(digits[i], mod);
        if (max_inc_val > 0) {
            digits[i] += max_inc_val;
            break;
        }
        int dec_val = min_dec(digits[i], mod);
        if (dec_val > 0) {
            min_dec_index = i;
            min_dec_val = dec_val;
        }
    }
    if (i == n) {
        digits[min_dec_index] -= min_dec_val;
    }
    
    print_digits(digits, n);   
    return 0;
}
