#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
 
const int N = 5e5 + 5;
const int mod = 1e9 + 7;
int n;
 
bool check(long long x) {
  long long ans = 0;
  int j = n;
  for (int i = 1; i <= n; i++) {
    while (1ll * i * j > x) {
      j--;
    }
    ans += j;
  }
  return (ans >= (1ll * n * n + 1) / 2);
}
 
void solve() {
  cin >> n;
  long long l = 1, r = 1ll * n * n, ans; 
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans;
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