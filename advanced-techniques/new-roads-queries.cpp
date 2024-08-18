#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
int n, m, q, l[N], r[N], u[N], v[N], lab[N], s[N], t[N], ans[N];
vector < int > g[N];
 
int root(int x) {
	return (lab[x] < 0 ? x : lab[x] = root(lab[x]));
}
 
void combine(int x, int y) {
	int u = root(x);
	int v = root(y);
	if (u == v) {
		return;
	} 
	lab[u] += lab[v];
	lab[v] = u;
}
 
int main() {
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> s[i] >> t[i];
		if (s[i] == t[i]) {
			ans[i] = 0;
			l[i] = 1;
		}
		else {
			ans[i] = -1;
			l[i] = 1, r[i] = m;
		}
	}
	for (int k = 1; k <= 20; k++) {
		for (int i = 1; i <= n; i++) {
			lab[i] = -1;
		}
		for (int i = 1; i <= m; i++) {
			g[i].clear();
		}
		for (int i = 1; i <= q; i++) {
			if (l[i] <= r[i]) {
				g[(l[i] + r[i]) / 2] .push_back(i);
			}
		}
		for (int i = 1; i <= m; i++) {
			combine(u[i], v[i]);
			for (int j : g[i]) {
				if (root(s[j]) == root(t[j])) {
					ans[j] = i;
					r[j] = i - 1;
				}
				else {
					l[j] = i + 1;
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << "\n";
	}
}
