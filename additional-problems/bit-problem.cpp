#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e6 + 5;
int n, dp[N], a[N], f[N];
 
int main() {
  if (fopen("test.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[a[i]]++;
    f[a[i]]++;
  }
 
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < (1 << 20); j++) {
      if (j >> i & 1) {
        dp[j] += dp[j ^ (1 << i)];
      }
    }
  }
 
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < (1 << 20); j++) {
      if (!(j >> i & 1)) {
        f[j] += f[j ^ (1 << i)];
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    cout << dp[a[i]] << " " << f[a[i]] << " " << n - dp[(1 << 20) - 1 - a[i]] << "\n";
  }
}
