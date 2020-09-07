#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int len = s.size();
	int ans = 0;
	for (int i = 0; i < len; ) {
		char ch = s[i];
		int cnt = 0;
		while (ch == s[i]) {
			cnt++;
			i++;
		}
		ans = max(ans , cnt);
	}
	cout << ans << "\n";
	return 0;
}