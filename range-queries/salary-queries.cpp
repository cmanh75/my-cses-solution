#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
char c[N];
int n, q, a[N], x[N], y[N], it[N * 24], m;
map < int, int > pos;
vector < int > s;
 
void update(int i, int l, int r, int p, int v) {
	if (l > p || r < p) {
		return;
	}
	if (l == r) {
		it[i] += v;
		return;
	}
	int mid = (l + r) / 2;
	update(i * 2, l, mid, p, v);
	update(i * 2 + 1, mid + 1, r, p, v);
	it[i] = it[i * 2] + it[i * 2 + 1];
}
 
int get(int i, int l,int r, int x, int y) {
	if (l > y || r < x) {
		return 0;
	}
	if (l >= x && r <= y) {
		return it[i];
	}
	int mid = (l + r) / 2;
	return get(i * 2, l, mid, x, y) + get(i * 2 + 1, mid + 1, r, x, y);
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.push_back(a[i]);
	}
	for (int i = 1; i <= q; i++) {
		cin >> c[i] >> x[i] >> y[i];
		if (c[i] == '!') {
			s.push_back(y[i]);
		}
	}
	sort(s.begin(), s.end());
	s.resize(distance(s.begin(), unique(s.begin(), s.end())));
	for (int i = 0; i < s.size(); i++) {
		pos[s[i]] = i + 1;
	}
	m = s.size();
	for (int i = 1; i <= n; i++) {
		update(1, 1, m, pos[a[i]], 1);
	}
	for (int i = 1; i <= q; i++) {
		if (c[i] == '!') {
			update(1, 1, m, pos[a[x[i]]], -1);
			update(1, 1, m, pos[y[i]], 1);
			a[x[i]] = y[i];
		}
		else {
			int l = lower_bound(s.begin(), s.end(), x[i]) - s.begin() + 1;
			int r = upper_bound(s.begin(), s.end(), y[i]) - s.begin();
			cout << get(1, 1, m, l, r) << "\n";
		}
	}
}
