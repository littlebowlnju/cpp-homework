#include <iostream>
#include <cmath>
using namespace std;

bool isPar(int ax, int ay, int bx, int by) {
	return ax * by == ay * bx;
}

bool isRT(int ax, int ay, int bx, int by) {
	return ax * bx + ay * by == 0;
}

bool isIT(int ax, int ay, int bx,int by) {
	return pow(ax, 2) + pow(ay, 2) == pow(bx, 2) + pow(by, 2);
}

int findType(int x1, int y1, int x2, int y2, int x3, int y3) {
	// 1:ORT; 2:LRT; 3:OIT; 4:OT; 5:NT
	int BCx = x3 - x2, BCy = y3 - y2, ABx = x2 - x1, ABy = y2 - y1, ACx = x3 - x1, ACy = y3 - y1;
	if(isPar(BCx,BCy,ACx,ACy)||isPar(ABx,ABy,BCx,BCy)||isPar(ABx,ABy,ACx,ACy))
		return 5;
	bool RT = false, IT = false;
	if (isRT(BCx, BCy, ACx, ACy) || isRT(ABx, ABy, BCx, BCy) || isRT(ABx, ABy, ACx, ACy))
		RT = true;
	if (isIT(BCx, BCy, ACx, ACy) || isIT(ABx, ABy, BCx, BCy) || isIT(ABx, ABy, ACx, ACy))
		IT = true;
	if (RT && IT)
		return 2;
	if (RT)
		return 1;
	if (IT)
		return 3;
	return 4;
}

int main() {
	int x1, y1, x2, y2, x3, y3;
	char c;
	cin >> c >> x1 >> c >> y1 >> c >> x2 >> c >> y2 >> c >> x3 >> c >> y3 >> c;
	int res = findType(x1, y1, x2, y2, x3, y3);
	switch (res) {
	case 1:cout << "ORT"; break;
	case 2:cout << "LRT"; break;
	case 3:cout << "OIT"; break;
	case 4:cout << "OT"; break;
	case 5:cout << "NT"; break;
	}
}