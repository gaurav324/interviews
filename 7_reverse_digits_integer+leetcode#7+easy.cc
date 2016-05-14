#include <iostream>
using namespace std;

long long reverse(int x) {
	long long ans = 0;
	int is_negative = x < 0 ? -1 : 1;
	x = x * is_negative;

	long y;
	while (x > 0) {
		ans = (ans*10) + x % 10;
		if (ans > INT_MAX) { return 0;} // Return Zero if there is integer overflow.
		x = x / 10;
	}
		
	return (int)ans * is_negative;
}

int main() {
	cout << "123 = " << reverse(123) << endl;
	cout << "1 = " << reverse(1) << endl;
	cout << "-123 = " << reverse(-123) << endl;
	cout << "1000 = " << reverse(1000) << endl;
	cout << "5555 = " << reverse(5555) << endl;
}
