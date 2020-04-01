# include <iostream>
# include <algorithm>
using namespace std;

int row = 0;
void getFourNumSum(int a[], int n, int sum, int idx, int tmp_idx, int tmp[], int res[][4]) {
	if (tmp_idx == 3&& idx < n&&a[idx] == sum) {
		tmp[tmp_idx] = a[idx];
		for (int j = 0; j < 4; j++) {
			res[row][j] = tmp[j];
		}row++;
	}
	if (idx == n||tmp_idx>3) {
		return;
	}
	else {
		tmp[tmp_idx] = a[idx];
		getFourNumSum(a, n, sum - a[idx], idx + 1, tmp_idx + 1, tmp, res);
		if (a[idx+1]==a[idx])
		{	
			int j;
			for (j = 1; j < n - idx; j++) {
				if (a[idx + j] != a[idx]) {
					break;
				}
			}
			getFourNumSum(a, n, sum, idx + j, tmp_idx, tmp, res);
		}
		else {
			getFourNumSum(a, n, sum, idx + 1, tmp_idx, tmp, res);
		}
	}
}

int main() {
	int a[1000],target,x;
	int idx = 0;
	char c;
	c=getchar();
	while (cin>>x) {
		a[idx++] = x;
		c = getchar();
		if (c == ']') {
			break;
		}
	}
	cin >> target;
	sort(a, a + idx);
	/*for (int i = 0; i < idx; i++) {
		cout << a[i] << " ";
	}*/
	int res[1000][4];
	int tmp[4] = {0};
	getFourNumSum(a, idx, target, 0, 0, tmp, res);
	if (row == 0) {
		cout << -1<<endl;
	}
	else {
		for (int i = 0; i < row; i++) {
			cout << "[" << res[i][0] << ", " << res[i][1] << ", " << res[i][2] << ", " << res[i][3] << "]" << endl;
		}
	}
}