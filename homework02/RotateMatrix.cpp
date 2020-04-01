# include <iostream>
using namespace std;

void mode0(int arr[20][20], int size) {
	//mode 0 means no rotate(360/360)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j];
			if (j == size - 1) {
				cout << '\n';
			}
			else {
				cout << ' ';
			}
		}
	}
}

void mode1(int arr[20][20], int size) {
	//mode1 means rotate 90 /360
	for (int j = 0; j < size; j++) {
		for (int i = size - 1; i >=0; i--) {
			cout << arr[i][j];
			if (i == 0) {
				cout << "\n";
			}
			else {
				cout << ' ';
			}
		}
	}
}

void mode2(int arr[20][20], int size) {
	//mode2 means rotate 180/360
	for (int i = size - 1; i >= 0; i--) {
		for (int j = size - 1; j >= 0; j--) {
			cout << arr[i][j];
			if (j == 0) {
				cout << '\n';
			}
			else {
				cout << ' ';
			}
		}
	}
}

void mode3(int arr[20][20], int size) {
	//mode3 means rotate 270/360
	for (int j = size - 1; j >=0; j--) {
		for (int i = 0; i < size; i++) {
			cout << arr[i][j];
			if (i == size - 1) {
				cout << '\n';
			}
			else {
				cout << ' ';
			}
		}
	}
}


int main() {
	int matrix[20][20];
	int i = 0, j = 0,x;
	int deg;
	while (cin>>x) {
		matrix[i][j] = x;
		j++;
		if (cin.get() == '\n')
			break;
	}
	int n = j;
	/*cout << "n=" << n << endl;*/
	for (i = 1; i < n; ++i) {
		for (j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	cin >> deg;
	int mode = (deg / 90) % 4;
	switch(mode)
	{
	case 0:
		mode0(matrix, n);
		break;
	case 1:
 		mode1(matrix, n);
		break;
	case 2:
		mode2(matrix, n);
		break;
	case 3:
		mode3(matrix, n);
	}

}