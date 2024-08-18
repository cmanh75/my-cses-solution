#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
int a[N], n, o = 0, q, rt[N], u = 1;
 
struct Node {
  int l, r;
  long long sum;
  Node() {
    l = 0, r = 0, sum = 0;
  }
} it[N * 25];
 
void update(int &i, int l, int r, int p, int val) {
  if (!i) {
    i = ++o;
  }
  if (l == r) {
    it[i].sum = a[l];
    return;
  }
  int mid = (l + r) / 2;
  if (mid >= p) {
    update(it[i].l, l, mid, p, val);
  }
  else {
    update(it[i].r, mid + 1, r, p, val);
  }
  it[i].sum = (it[it[i].l]).sum + (it[it[i].r]).sum;
}
 
void update1(int &i, int e, int l, int r, int p, int x) {
  i = ++o;
  if (l == r) {
    it[i].sum = x;
    return;
  }
  int mid = (l + r) / 2;
  if (mid >= p) {
    it[i].r = it[e].r;
    update1(it[i].l, it[e].l, l, mid, p, x);
  }
  else {
    it[i].l = it[e].l;
    update1(it[i].r, it[e].r, mid + 1, r, p, x);
  }
  it[i].sum = it[it[i].l].sum + it[it[i].r].sum;
}
 
long long get(int i, int l, int r, int le, int ri) {
  if (l > ri || r < le) {
    return 0;
  }
  if (l >= le && r <= ri) {
    return it[i].sum;
  }
  int mid = (l + r) / 2;
  return get(it[i].l, l, mid, le, ri) + get(it[i].r, mid + 1, r, le, ri);
}
 
int main() {
  if (fopen("test.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
	cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(rt[1], 1, n, i, a[i]);
  }
  while (q--) {
    int c, l, r, x;
    cin >> c >> l;
    if (c == 3) {
      rt[++u] = ++o;
      it[rt[u]] = it[rt[l]]; 
    }
    if (c == 1) {
      cin >> r >> x;
      update1(rt[l], rt[l], 1, n, r, x);
    }
    if (c == 2) {
      cin >> r >> x;
      cout << get(rt[l], 1, n, r, x) << "\n";
    }
  }
}