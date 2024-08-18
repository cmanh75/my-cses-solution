#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
int n, m, q, cnt = 0, low[N], d[N], num[N], par[N], xx[N], yy[N];
vector < int > a[N], b[N];
bitset < 50002 > f[50002];
stack < int > st;
 
void tarjan(int i) {
  st.push(i);
  num[i] = low[i] = ++cnt;
  for (int j : a[i]) {
    if (!num[j]) {
      tarjan(j);
    }
    low[i] = min(low[j], low[i]);
  }
  if (num[i] == low[i]) {
    int x;
    do {
      x = st.top();
      st.pop();
      par[x] = i;
      low[x] = 1e9;
    } while (x != i);
  }
}
 
void dfs(int i) {
  f[i].set(i);
  d[i] = 1;
  for (int j : b[i]) {
    if (!d[j]) {
      dfs(j);
    }
    f[i] |= f[j];
  }
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("test.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    cin >> xx[i] >> yy[i];
    a[xx[i]].push_back(yy[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (!num[i]) {
      tarjan(i);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (par[xx[i]] != par[yy[i]]) {
      b[par[xx[i]]].push_back(par[yy[i]]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!d[i]) {
      dfs(i);
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (par[x] == par[y]) {
      cout << "YES" << "\n";
    }
    else {
      if (f[par[x]].test(par[y])) {
        cout << "YES" << "\n";
      }
      else {
        cout << "NO" << "\n";
      }
    }
  }
}
