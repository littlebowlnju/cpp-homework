# include <iostream>
# include <math.h>
# include <string.h>
# include <algorithm>
using namespace std;

struct Transaction {
	char name[11];
	int time;
	int amount;
	char city[11];
};

bool notValid(Transaction t1, Transaction t2) {
	if (strcmp(t1.name,t2.name)==0 && strcmp(t1.city, t2.city) != 0&& abs(t1.time - t2.time) <= 60) {
		return true; //these two transactions are invalid
	}return false;
}

int main() {
	Transaction t[10000],rest[1000];
	int idx = 0,city_idx = 0, name_idx = 0;
	char c;
	cin >> c;
	while (c != ']') {
		cin >> c;
		if (c == ']') {
			break;
		}
		cin >> c;
		name_idx = 0;
		while (c != ',') {
			t[idx].name[name_idx++] = c;
			c = getchar();
		}
		t[idx].name[name_idx] = '\0';
		/*cout << t[idx].name;*/
		cin >> t[idx].time;
		/*cout << t[idx].time;*/
		cin >> c;
		cin >> t[idx].amount;
		/*cout << t[idx].amount;*/
		cin >> c>>c;
		city_idx = 0;
		while (c != '"') {
			t[idx].city[city_idx++] = c;
			c = getchar();
		}t[idx].city[city_idx] = '\0';
		/*cout << t[idx].city;*/
		idx += 1;
		c = getchar();
	}

	int isIn[1001] = { 0 };
	for (int i = 0; i < idx; ++i) {
		if (t[i].amount > 1000) {
			isIn[i] = 1;
		}
		for (int j = i + 1; j < idx; ++j) {
			if (notValid(t[i], t[j])) {
				isIn[i] = 1;
				isIn[j] = 1;
			}
		}
	}

	cout << '[';
	bool add = false;
	for (int i = 0; i < idx; i++) {
		if (isIn[i] == 1) {
			if (add) {
				cout << ',';
			}
			cout << '"' <<t[i].name << ',' << t[i].time << ',' << t[i].amount << ',' << t[i].city << '"';
			add = true;
		}
	}cout << ']';

}