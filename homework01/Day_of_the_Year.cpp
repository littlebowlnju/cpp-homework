#include <iostream>
using namespace std;

int dayOfYear(int year, int month, int day) {
	int preDays[] = { 0,31,59,90,120,151,181,212,243,273,304,334 }; //preDays keeps the total days before this month
	int dayofMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		for (int i = 2; i < 12; i++) {
			preDays[i] += 1;
			dayofMonth[1] = 29;
		}
	}
	if (day > dayofMonth[month - 1] || day <= 0||month<=0||month>12||year<=0)
		return -1;
	return preDays[month - 1] + day;
}

int main() {
	int year, month, day;
	char c;
	cin >> year >> c >> month >> c >> day;
	cout << dayOfYear(year,month,day);
}