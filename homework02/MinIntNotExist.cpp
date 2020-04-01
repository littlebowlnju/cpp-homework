# include <iostream>
# include <algorithm>
using namespace std;

int main() {
	int a[50],idx=0;
	char c;
	cin >> c;
	while (c != ']') {
		cin >> a[idx++] >> c;
	}
	sort(a, a + idx);
	int res = 1;
	bool find = false;
	for (int i = 0; i < idx; ++i) {
		if (a[i] <= 0)
			continue;
		if (a[i] != res) {
			find = true;
			cout << res;
			break;
		}res++;
	}
	if (!find)
		cout << res;
}