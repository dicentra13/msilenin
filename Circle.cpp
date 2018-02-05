#include <iostream>

using namespace std;

struct Circle {
	Circle()
        : x(0.0)
        , y(0.0) 
        , r(1.0) // I don't know what a circle is standard, so I decided to write so
    {}
    
    Circle(double a, double b, double R)
    	: x(a)
    	, y(b)
    	, r(R)
    {}
    
    Circle(const Circle& c)
    	: x(c.x)
    	, y(c.y)
    	, r(c.r)
    {
    	cout << "copy ctor" << endl;  // For verification
	}
    
    Circle& operator=(const Circle& c) {
    	cout << "assignment" << endl;  // For verification
    	
    	x = c.x;
    	y = c.y;
    	r = c.r;
    	return *this;
	}
	
	double length(const Circle& c) const {
		return 2 * 3,14 * c.r;
	}
	
    double area(const Circle& c) const {
    	return length(c) * r / 2;
    	// return 3,14 * pow(c.r, 2);
	}
    
	double x;
	double y;
	double r;
};

ostream& operator<<(ostream& os, const Circle& c)
{
    os << c.x << " " << c.y << " " << c.r;
    return os;
}

istream& operator>>(istream& is, Circle& c)
{
    is >> c.x >> c.y >> c.r;
    return is;
}

int main () {
	Circle c1(2, 1, 3);
	c1.r = 4;
	cout << c1 << endl;
	
	Circle c2;
	cin >> c2;
	cout << c2 << endl;
	
	c1 = c2;
	cout << c1 << endl;
	
	Circle c3 = c2;
	return 0;
}
