#include <iostream>
#include <string>
using namespace std;

const int N = 50;
int len, set[N];
char tar,chset[N],pick[N];
bool isLast = true;

void dfs(int depth, int cur, int size, bool exist) {
	/*
	defth-遍历到的当前数组位置，cur-目前数组长度，size-要求数组长度，exist-指定字符是否在数组中
	*/
	if (depth == len) {
		if (cur != size || !exist)
			return;
		if (isLast)
			isLast = false;
		else
			cout << ',';
		cout << '{';
		for (int i = 0; i < cur; i++)
			cout << pick[i] <<( i == cur - 1 ? '}' : ',');
		return;
	}
	if (cur < size) {
		pick[cur] = chset[depth];
		dfs(depth + 1, cur + 1, size, exist || chset[depth] == tar);
	}
	dfs(depth + 1, cur, size, exist);  // 
}

coc
int main() {
	string inp;
	getline(cin,inp);
	len = 0;
	for (int i = 0; i < inp.size()-2; i++) {
		if (inp[i] != '{'&&inp[i] != '}'&&inp[i] != ',') {
			chset[len++] = inp[i];
		}
	}
	tar = inp[inp.size()-1];
	for (int i = 0; i < len; i++)
		for (int j = i + 1; j < len; j++) {
			if (chset[i]>chset[j]){
				swap(chset[i], chset[j]);
			}
		}
	for (int i = 1; i <= len; i++)
		dfs(0, 0, i, false);
}