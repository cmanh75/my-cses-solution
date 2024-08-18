#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
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
 
long long cross(point x, point y, point z) {
	vect a = crea(x, y);
	vect b = crea(x, z);
	long long t = 1ll * a.x * b.y - 1ll * a.y * b.x; 
	return t;
} 
 
bool cmp(point a, point b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}
 
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	sort(p + 1, p + n + 1, cmp);
	point ps = p[1];
	point pt = p[n];
	vector < point > up, dw;
	for (int i = 1; i <= n; i++) {
		if (cross(ps, pt, p[i]) <= 0) {
			while (dw.size() > 1 && cross(dw[dw.size() - 2], dw.back(), p[i]) < 0) {
				dw.pop_back();
			}
			dw.push_back(p[i]);
		}
		if (cross(ps, pt, p[i]) >= 0) {
			while (up.size() > 1 && cross(up[up.size() - 2], up.back(), p[i]) > 0) {
				up.pop_back();
			}
			up.push_back(p[i]);
		}
	}
	cout << dw.size() + up.size() - 2 << "\n";
	for (point j : dw) {
		cout << j.x << " " << j.y << "\n";
	}
	for (int i = up.size() - 2; i > 0; i--) {
		cout << up[i].x << " " << up[i].y << "\n";
	}
}
