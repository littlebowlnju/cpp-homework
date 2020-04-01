# include <iostream>
# include <string.h>
using namespace std;

//int times[9] = { 0 };
bool checkRow(int s[10][10]) {
	for (int i = 0; i < 9; i++) {
		/*memset(times, 0, sizeof(int)*9);*/
		int times[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			if (0 < s[i][j] && s[i][j] < 10) {
				times[s[i][j] - 1] += 1;
				if (times[s[i][j] - 1] > 1) 
					return false;
			}
		}
	}return true;
}

bool checkColumn(int s[10][10]) {
	for (int j = 0; j < 9; j++) {
		/*memset(times, 0, sizeof(int)*9);*/
		int times[9] = { 0 };
		for (int i = 0; i < 9; i++) {
			if (0 < s[i][j] && s[i][j] < 10) {
				times[s[i][j] - 1] += 1;
				if (times[s[i][j] - 1] > 1)
					return false;
			}
		}
	}return true;
}

bool checkBlocks(int s[10][10]) {
	for (int k = 0; k < 9; k +=3) {
		for (int l = 0; l < 9; l+=3) {
			/*memset(times, 0, sizeof(int)*9);*/
			int times[9] = { 0 };
			for (int i = k; i < k + 3; i++) {
				for (int j = l; j < l + 3; j++) {
					if (0 < s[i][j] && s[i][j] < 10) {
						times[s[i][j] - 1] += 1;
						if (times[s[i][j] - 1] > 1)
							return false;
					}
				}
			}
		}
	}
	return true;
}


int main() {
	int sudoku[10][10];
	char c;
	for (int i = 0; i < 9; ++i) {
		int j = 0;
		while (true) {
			c = cin.get();
			if ('0' < c && c <= '9') {
				sudoku[i][j] = int(c-'0');
				j++;
			}
			else if (c == '.') {
				sudoku[i][j] = -1; //use -1 in sudoku to mean the space is blank
				j++;
			}
			if (c == '\n'||c==EOF)
				break;
		}
	}
	if (checkRow(sudoku) && checkColumn(sudoku)&&checkBlocks(sudoku))
		cout << "true";
	else {
		cout << "false";
	}

}