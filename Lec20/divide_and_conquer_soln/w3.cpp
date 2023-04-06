// Divide-and-conquer worksheet
// Solution to problem #3
// Omid Ardakanian, 2022

#include <iostream>
#include <cmath>	// log2, sqrt
#include <cassert>
#include <iomanip>	// setprecision

using namespace std;

// evaluates function f at x
double f(double x, double y) {
	return sqrt(x) + log2(x+1) - y;
}

// Given a function func() that is continuous in the range
// [low, high], this will return an approximate root of func().
// Assumptions: low <= high
//
// The first parameter is a function pointer. "func"
// is the variable name, the leading "double" is the return type,
// and the arguments in parenthesis are the function parameters.
// You *need* the parenthesis around (*func) so the compiler
// knows it is a function pointer.
//
// You can declare variables with function pointer type:
// e.g., double (*fn_ptr)(double) = find_root;
double find_root(double (*func)(double, double), double low, double high, double y) {
	double tol = 1e-8; // 10^(-8)

	// f must be a continuous function for this algorithm to work
	while (high - low > tol) {
		double mid = (high + low)/2;
		if (func(mid, y) == 0) {
			return mid;
		} else if (func(mid, y) > 0) {
			high = mid;
		} else {
			low = mid;
		}
	}
	return (high + low)/2;
}

int main() {
	double result;

	// sets the number of decimal places because of std::fixed
	cout << setprecision(7) << fixed;

	double y = 3.8226391;
	result = find_root(f, 0, y * y, y);
	cout << result << endl;
	
	return 0;
}