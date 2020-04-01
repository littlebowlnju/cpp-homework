#include <iostream>
#include <climits>
using namespace std;

int x_pow_y(int x, int y) {
	long long res=1;
	int max = INT_MAX;
	int min = INT_MIN;
	for (int i = 0; i < y; i++) {
		if (res*x > max || res * x < min) {
			return -1;
		}res *= x;
	}return (int)res;
}

int main() {
	char c;
	int x, y;
	cin >> c >> c >> x >> c >> c >> c >> y;
	cout << x_pow_y(x, y);
}