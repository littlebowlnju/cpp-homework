# include <iostream>
# include <algorithm>
using namespace std;

int main() {
	int idx=0;
	long long a[1000], num;
	while (cin >> num ) {
		a[idx++] = num;
		if (cin.get() == '\n')
			break;
	}
	/*cout << idx << endl;*/
	sort(a, a + idx );
	long long length[1000], res = 1;
	length[0] = 1;
	for (int i = 1; i < idx ; i++) {
		if (a[i] == a[i - 1] + 1) {
			length[i] = length[i - 1] + 1;
			if (length[i] > res) {
				res = length[i];
			}
		}
		else if (a[i] == a[i - 1]) {
			length[i] = length[i - 1];
		}
		else {
			length[i] = 1;
			/*if (length[i] > res) {
				res = length[i];
			}*/
		}
	}
	cout << res;
}
