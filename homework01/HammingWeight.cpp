#include <iostream>
using namespace std;

int getNumberof1(int x) {
	int res = 0;
	while (x != 0) {
		res++;
		x = x & (x - 1);
	}
	return res;
}

int main() {
	int x;
	cin >> x;
	cout << getNumberof1(x);
}