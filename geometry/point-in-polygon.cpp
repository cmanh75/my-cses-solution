#include <bits/stdc++.h>
using namespace std;
 
const int N = 2005;
 
struct point {
	int x, y;
} p[N];
 
struct vect {
  int x, y;
 
  long long operator ^ (vect a) {
    long long z = 1ll * x * a.y - 1ll * y * a.x;
    return z;
  }
};
 
vect vec(point a, point b) {
  return {b.x - a.x, b.y - a.y};
}
 
int cw(point a, point b, point c) {
  long long z = vec(a, b) ^ vec(a, c);
  return (z > 0 ? 1 : (z < 0 ? -1 : 0));
}
 
int main() {
  if (fopen("test.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  int n, q;
	cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  p[n + 1] = p[1];
  while (q--) {
    cin >> p[0].x >> p[0].y;
    int ok = 0;
    for (int i = 1; i <= n; i++) {
      if (cw(p[i], p[0], p[i + 1]) == 0) {
        int mix = min(p[i].x, p[i + 1].x);
        int miy = min(p[i].y, p[i + 1].y);
        int mxx = max(p[i].x, p[i + 1].x);
        int mxy = max(p[i].y, p[i + 1].y);
        ok |= (p[0].x <= mxx && p[0].x >= mix && p[0].y <= mxy && p[0].y >= miy);
      }
    }
    if (ok == 1) {
      cout << "BOUNDARY" << "\n";
      continue;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (p[i].x <= p[0].x && p[i + 1].x > p[0].x) {
        ans += ((vec(p[0], p[i]) ^ vec(p[0], p[i + 1])) < 0);
      }
      if (p[i + 1].x <= p[0].x && p[i].x > p[0].x) {
        ans += ((vec(p[0], p[i + 1]) ^ vec(p[0], p[i])) < 0);
      }
    }
    if (ans & 1) {
      cout << "INSIDE" << "\n";
    }
    else {
      cout << "OUTSIDE" << "\n";
    }
  }
}
