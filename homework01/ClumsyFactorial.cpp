#include <iostream>
using namespace std;

int clumsyFactorial(int x) {
	char op = '*';
	int i = x,res=x;
	while (i > 1) {
		if (op == '*') {
			res *= i - 1; i--; op = '/'; continue;
		}
		else if (op == '/') {
			res /= i - 1; i--; op = '+'; continue;
		}
		else if (op == '+') {
			res += i - 1; i--; op = '-'; continue;
		}
		else if (op == '-') {
			if (i >3) {
				res -= (i - 1)*(i - 2) / (i - 3); i -= 3; op = '+';
			}
			else if (i == 3) {
				res -= 2; i -= 2; op = '/';
			}
			else if (i == 2) {
				res -= 1; i -= 1; op = '*';
			}
		}
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	cout << clumsyFactorial(n);
}