#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
int trie[N * 20][2], o = 0;
 
void add(int x) {
	int cur = 0;
	for (int i = 30; i >= 0; i--) {
		int u = (x >> i & 1);
		if (!trie[cur][u]) {
			trie[cur][u] = ++o;
		}
		cur = trie[cur][u];
	}
}
 
int get(int x) {
	int cur = 0, ans = 0;
	for (int i = 30; i >= 0; i--) {
		int u = x >> i & 1;
		if (trie[cur][1 - u]) {
			ans += (1 << i);
			cur = trie[cur][1 - u];
		}
		else {
            cur = trie[cur][u];
		}
	}
	return ans;
}
 
int main() {
    int n;
	cin >> n;
	int ans = 0, s = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		add(s);
		cin >> x;
		s ^= x;
		ans = max(ans, get(s));
	}
	cout << ans;
}
