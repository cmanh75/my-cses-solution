#include <bits/stdc++.h>
using namespace std;
 
struct point {
	int x;
	int y;
} p[6];
 
struct vect {
	int x;
	int y;
};
 
vect crea (point a, point b) {
	return {b.x - a.x, b.y - a.y};
}
 
int check(vect a, vect b) {
	long long z = 1ll * a.x * b.y - 1ll * a.y * b.x; 
	return (z > 0 ? 1 : (z == 0 ? 0 : -1));
} 
 
bool check1(int a, int b, int c, int d) {
	int mix = min(p[a].x, p[b].x);
	int mxx = max(p[a].x, p[b].x);
	int miy = min(p[a].y, p[b].y);
	int mxy = max(p[a].y, p[b].y);
	if (p[c].x >= mix && p[c].x <= mxx && p[c].y >= miy && p[c].y <= mxy) {
		return true;
	}
	if (p[d].x >= mix && p[d].x <= mxx && p[d].y >= miy && p[d].y <= mxy) {
		return true;
	}
	return false;
}
 
int main() {
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		cin >> p[1].x >> p[1]. y >> p[2].x >> p[2].y >> p[3].x >> p[3].y >> p[4].x >> p[4].y;
		if (check(crea(p[1], p[2]), crea(p[1], p[3])) == 0 && check(crea(p[1], p[2]), crea(p[1], p[4])) == 0) {
			if (check1(3, 4, 1, 2) || check1(1, 2, 3, 4)) {
				cout << "YES" << "\n";
				continue;
			}
			cout << "NO" << "\n";
			continue;
		}
		int c34 = check(crea(p[1], p[2]), crea(p[1], p[3])) * check(crea(p[1], p[2]), crea(p[1], p[4]));
		int c12 = check(crea(p[3], p[4]), crea(p[3], p[1])) * check(crea(p[3], p[4]), crea(p[3], p[2]));
		if (c34 <= 0 && c12 <= 0) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
}