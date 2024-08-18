#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
 
const int N = 1e5 + 5;
int n, m, q, lab[N], ans, res[N];
vector < pair < int, int > > s[N * 4];
map < pair < int, int >, int > d;
stack < pair < pair < int, int >, int > > st;
 
int root(int x) {
  return (lab[x] < 0 ? x : root(lab[x]));
}
 
void combine(int x, int y) {
  int u = root(x);
  int v = root(y);
  if (u == v) {
    st.push(mp(mp(0, 0), 0));
    return;
  }
  if (lab[u] > lab[v]) {
    swap(u, v);
  }
  st.push(mp(mp(u, v), lab[v]));
  lab[u] += lab[v];
  lab[v] = u;
  ans--;
}
 
void roll_back() {
  int u = st.top().first.first;
  int v = st.top().first.second;
  int z = st.top().second;
  if (u != v) {
    ans++;
    lab[u] -= z;
    lab[v] = z;
  }
  st.pop();
  return;
}
 
void update(int i, int l, int r, int le, int ri, pair < int, int > e) {
  if (l > ri || r < le) {
    return;
  }
  if (l >= le && r <= ri) {
    s[i].push_back(e);
    return;
  }
  int mid = (l + r) / 2;
  update(i * 2, l, mid, le, ri, e);
  update(i * 2 + 1, mid + 1, r, le, ri, e);
}
 
void cal(int i,int l, int r) {
  for (pair < int, int > e : s[i]) {
    combine(e.first, e.second);
  }
  if (l != r) {
    int mid = (l + r) / 2;
    cal(i * 2, l, mid);
    cal(i * 2 + 1, mid + 1, r);
  }
  else {
    res[l] = ans;
  }
  for (int j = s[i].size() - 1; j >= 0; j--) {
    roll_back();
  }
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("test.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    lab[i] = -1;
  }
  ans = n;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    d[mp(x, y)] = 1;
  }
  for (int i = 1; i <= q; i++) {
    int c, x, y;
    cin >> c >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    if (c == 1) {
      d[mp(x, y)] = i + 1; 
    }
    else {
      update(1, 1, q + 1, d[mp(x, y)], i, mp(x, y));
      d.erase(mp(x, y));
    }
  }
  for (auto [e, x] : d) {
    update(1, 1, q + 1, x, q + 1, e);
  }
  cal(1, 1, q + 1);
  for (int i = 1; i <= q + 1; i++) {
    cout << res[i] << " ";
  }
}