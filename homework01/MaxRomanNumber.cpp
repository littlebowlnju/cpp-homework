# include <iostream>
# include <string>
using namespace std;

int getRomanNumber(string s) {
	int len = s.size();
	int res = 0;
	int i = len - 1;
	while (i > -1) {
		if (s[i] == 'I')
			res += 1;
		if (s[i] == 'V') {
			if (i - 1 > -1 && s[i - 1] == 'I'){
				res += 4; i -= 2; continue;
			}
			else { res += 5; }
		}if (s[i] == 'X') {
			if (i - 1 > -1 && s[i - 1] == 'I') {
				res += 9; i -= 2; continue;
			}
			else { res += 10; }
		}if (s[i] == 'L') {
			if (i - 1 > -1 && s[i - 1] == 'X') {
				res += 40; i -= 2; continue;
			}
			else { res += 50; }
		}if (s[i] == 'C') {
			if (i - 1 > -1 && s[i - 1] == 'X') {
				res += 90; i -= 2; continue;
			}
			else {
				res += 100;
			}
		}if (s[i] == 'D') {
			if (i - 1 > -1 && s[i - 1] == 'C') {
				res += 400; i -= 2; continue;
			}
			else {
				res += 500;
			}
		}if (s[i] == 'M') {
			if (i - 1 > -1 && s[i - 1] == 'C') {
				res += 900; i -= 2; continue;
			}
			else {
				res += 1000;
			}
		}i--;
	}
	return res;
}

int main() {
	string s;
	int maxRes = 0,tmpRes;
	while (cin >> s) {
		tmpRes = getRomanNumber(s);
		maxRes = maxRes < tmpRes ? tmpRes : maxRes;
		if (getchar() == '\n')
			break;
	}
	cout << maxRes;
}
