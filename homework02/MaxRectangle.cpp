# include <iostream>
using namespace std;

int main() {
	int height[100],res=0,idx=0,x;
	while (cin >> x) {
		height[idx++] = x;
		if (cin.get() == '\n') {
			break;
		}
	}
	// idx now means the length of height
	for (int i = 0; i < idx; i++) {
		int min_height = 100;
		for (int j = i; j < idx; j++) {
			int cur_height = (height[j] < min_height ? height[j] : min_height);
			int cur_area = cur_height * (j + 1 - i);
			res = (cur_area > res ? cur_area : res);
			min_height = cur_height;  //minheight needs to be updated
		}
	}
	cout << res;
}