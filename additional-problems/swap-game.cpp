#include<bits/stdc++.h>
using namespace std;
 
int p[10];
unordered_map < int, int > d;
 
struct grid {
  int a[3][3];
 
  int trans() {
    int z = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        z += a[i][j] * p[(i * 3 + j)];
      } 
    }
    return z;
  }
} s;
 
grid trans1(int x) {
  grid z;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      z.a[i][j] = x / p[i * 3 + j] % 10;
    }
  }
  return z;
}
 
int main() {
  if (fopen("test.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  p[0] = 1;
  for (int i = 1; i <= 8; i++) {
    p[i] = p[i - 1] * 10;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> s.a[i][j];
    }
  }
  queue < int > qu;
  qu.push(s.trans());
  while (qu.size()) {
    int x = qu.front();
    qu.pop();
    if (x == 987654321) {
      cout << d[x];
      return 0;
    }
    grid z = trans1(x);
    for (int i = 0; i < 3; i++) {
      for (int j = 1; j < 3; j++) {
        swap(z.a[i][j], z.a[i][j - 1]);
        int y = z.trans();
        if (!d.count(y)) {
          qu.push(y);
          d[y] = d[x] + 1;
        }
        swap(z.a[i][j], z.a[i][j - 1]);
      }
    }
    for (int j = 0; j < 3; j++) {
      for (int i = 1; i < 3; i++) {
        swap(z.a[i][j], z.a[i - 1][j]);
        int y = z.trans();
        if (!d.count(y)) {
          qu.push(y);
          d[y] = d[x] + 1;
        }
        swap(z.a[i][j], z.a[i - 1][j]);
      }
    }
  }
}