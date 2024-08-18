#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
 
const int N = 2e3 + 5;
const int mod = 1e9 + 7;
long long f[20][11][2][2];
string a, b, s;
 
long long cal(int i, int p, int ok, int u) {
  if (i == s.size()) {
    return 1;
  }
  if (f[i][p][ok][u] + 1) {
    return f[i][p][ok][u];
  }
  long long &res = f[i][p][ok][u];
  res = 0;
  int end = (ok != 0 ? 9 : s[i] - '0');
  for (int j = 0; j <= end; j++) {
    if (j == p) {
      continue;
    }
    res += cal(i + 1, ((u == 0 && j == 0) ? 10 : j), ok | (j < s[i] - '0'), u | (j != 0));
  }
  return res;
}
 
long long precal(string t) {
  memset(f, -1, sizeof(f));
  s = t;
  return cal(0, 10, 0, 0);
}
 
void solve() {
  cin >> a >> b;
  if (a != "0") {
    for (int i = a.size() - 1; i >= 0; i--) {
      if (a[i] == '0') {
        a[i] = '9';
      }
      else {
        a[i]--;
        break;
      }
    }
    cout << precal(b) - precal(a);
  }
  else {
    cout << precal(b);
  }
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("test.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  int test = 1;
  while (test--) {
    solve();
  }
}
