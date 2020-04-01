# include <iostream>
using namespace std;

int main() {
	char s[10001],s1[10001];
	int idxx = 0;
	/*while (c!=EOF) {
		s[idxx++] = c;
		c = getchar();
		if (c == '\n')
			break;
	}*/
	cin.getline(s, 10001);
	/*cout << s<<endl;*/
	int n = strlen(s),idx=1;
	int count = 1;
	/*cout << n;*/
	char tmp = s[0];
	int i = 1;
	s1[0] = tmp;
	int times[100],times_idx=0;
	while (i < n) {
		if (s[i] != tmp) {
			times[times_idx++] = count;
			s1[idx++] = s[i];
			tmp = s[i];
			count = 1;
		}
		else {
			count++;
		}i++;
	}
	times[times_idx++] = count;
	/*cout << count<<endl;*/
	/*s1[idx++] = count+'0'; */ //the last character's show times,and idx means the length of s1
	if (idx*2 > n) {
		s[n] = '\0';
		cout << s;
	}
	else {
		for (int i = 0; i < idx; i++) {
			cout << s1[i] << times[i];
		}
	}
}