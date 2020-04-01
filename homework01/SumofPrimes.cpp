#include <iostream>
using namespace std;

bool isPrime(int x) {
	if (x == 1)
		return false;
	for (int i = 2; i < x; i++) {
		if (x%i == 0) {
			return false;
		}
	}return true;
}

int main() {
	char c;
	int n, m;
	int res = 0;
	cin >>c>> n >> m >> c;
	for (int i = n; i <= m; i++) {
		if (isPrime(i)) {
			res += i;
		}
	}
	cout << res;
}