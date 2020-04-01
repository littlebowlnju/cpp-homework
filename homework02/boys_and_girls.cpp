# include <iostream>
using namespace std;

int main() {
	char s[1000];
	cin >> s;
	int n = strlen(s);
	int boys=0, girls=0;
	int visited[1000] = { 0 };
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;
		else if (s[i] == '.')
			continue;
		else if (s[i] == 'b') {
			boys += 1;
			visited[i] = 1;
			if (s[i + 1] == 'o') {
				visited[i + 1] = 1;
			}if (s[i + 2] == 'y') {
				visited[i + 2] = 1;
			}
		}
		else if (s[i] == 'o') {
			boys += 1;
			visited[i] = 1;
			if (s[i + 1] == 'y') {
				visited[i + 1] = 1;
			}
		}
		else if (s[i] == 'y') {
			boys += 1;
			visited[i] = 1;
		}
		else if (s[i] == 'g') {
			girls += 1;
			visited[i] = 1;
			if (s[i + 1] == 'i')
				visited[i + 1] = 1;
			if (s[i + 2] == 'r')
				visited[i + 2] = 1;
			if (s[i + 3] == 'l')
				visited[i + 3] =1;
		}
		else if(s[i]=='i'){
			girls += 1;
			visited[i] = 1;
			if (s[i + 1] == 'r')
				visited[i + 1] = 1;
			if (s[i + 2] == 'l')
				visited[i + 2] = 1;
		}
		else if (s[i] == 'r') {
			girls += 1;
			visited[i] = 1;
			if (s[i + 1] == 'l')
				visited[i + 1] = 1;
		}
		else if (s[i] == 'l') {
			girls += 1;
			visited[i] = 1;
		}
	}
	cout << boys << " " << girls;
}