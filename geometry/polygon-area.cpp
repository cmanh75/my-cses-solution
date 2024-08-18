#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
int n;
 
struct point {
	int x;
	int y;
} p[N];
 
struct vect {
	int x;
	int y;
};
 
vect crea (point a, point b) {
	return {b.x - a.x, b.y - a.y};
}
 
long long cross(vect a, vect b) {
	long long z = 1ll * a.x * b.y - 1ll * a.y * b.x; 
	return z;
} 
 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	p[n + 1] = p[1];
	long long ans = 0;
	for (int i = 2; i <= n + 1; i++) {
		vect a = {p[i - 1].x, p[i - 1]. y};
		vect b = {p[i].x, p[i]. y};
		ans += cross(a, b);
	}
	cout << abs(ans);
}