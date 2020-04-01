# include <iostream>
using namespace std;

int main() {
	int a[1000],x,idx=0;
	while (cin >> x) {
		a[idx++] = x;
		if (cin.get() == '\n')
			break;
	}
	int i = 0, j, k;
	while (i < idx) {
		j = i+1;
		while (j < idx) {
			if (a[i] == a[j]) {
				k = j;
				while (k< idx - 1) {
					a[k] = a[k + 1];
					k++;
				}idx--;
				j--;
			}j++;
		}i++;
	}
	for (int i = 0; i < idx; i++) {
		cout << a[i];
		if (i != idx - 1) {
			cout << " ";
		}

	}
}