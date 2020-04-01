#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int showTimes(char c, string s) {
	int len = s.size(),res=0;
	for (int i = 0; i < len; i++) {
		if (s[i] == c || s[i] == c - 32)
			res += 1;
	}return res;
}

int main() {
	int n;
	int res[26];
	string finalStr, tmpStr;
	cin >> n;
	for (int i = 0; i <=n; i++) {
		getline(cin, tmpStr);
		finalStr += tmpStr; 
	}
	char c = 'a';
	for (int i = 0; i < 26; i++) {
		int times = showTimes(c + i, finalStr);
		res[i] = times > 0 ? times : 0;
	}
	sort(res, res + 26);
	cout << '[';
	for (int i = 0; i < 25; i++) {
		if (res[i]) {
			cout << res[i] << ',';
		}
	}if (res[25]) { cout << res[25]; }
	cout << ']';
}