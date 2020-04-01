#include <iostream>
#include <string>
using namespace std;

void toUpper(string& s) {
	int len =s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a'&&s[i] <= 'z') {
			s[i] += 'A' - 'a';
		}
	}
}

int main() {
	string s,res;
	int k;
	cin >> s >> k;
	int i = s.size() - 1,count=0;
	while (i>-1) {
		if (s[i] != '-') {
			res = s[i] + res;
			count++;
		}if (count == k && i!=0) {
			res = '-' + res;
			count = 0;
		}i--;
	}
	toUpper(res);
	cout << res;
}

