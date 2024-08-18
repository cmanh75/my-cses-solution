#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e5 + 5;
 
struct tree {
	int val[N * 4], pre[N * 4], suf[N * 4], len[N * 4];
 
	void combine(int i) {
		val[i] = max({val[i * 2 + 1], val[i * 2], suf[i * 2] + pre[i * 2 + 1]});
		pre[i] = pre[i * 2];
		if (len[i * 2] == pre[i * 2]) {
			pre[i] += pre[i * 2 + 1];
		}
		suf[i] = suf[i * 2 + 1];
		if (suf[i * 2 + 1] == len[i * 2 + 1]) {
			suf[i] += suf[i * 2];
		}
		len[i] = len[i * 2] + len[i * 2 + 1];
	}
	
	void update(int i, int l, int r, int pos, int v) {
		if (l > pos || r < pos) {
			return;
		}
		if (l == r) {
			val[i] = pre[i] = suf[i] = v;
			len[i] = 1;
			return;
		}
		int mid = (l + r) / 2;
		update(i * 2, l, mid, pos, v);
		update(i * 2 + 1, mid + 1, r, pos, v);
		combine(i);
	}
} it[2];
 
int main() {
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 1; i <= n; i++) {
		it[0].update(1, 1, n, i, 0);
		it[1].update(1, 1, n, i, 0);
	}
	for (int i = 0; i < s.size(); i++) {
		it[s[i] - '0'].update(1, 1, n, i + 1, 1);
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		it[s[x - 1] - '0'].update(1, 1, n, x, 0);
		it['1' - s[x - 1]].update(1, 1, n, x, 1);
		s[x - 1] = '1' - s[x - 1] + '0';
		cout << max(it[0].val[1], it[1].val[1]) << " ";
	}
}
