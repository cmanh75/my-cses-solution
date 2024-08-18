#include <stdio.h>
#include <queue>
using namespace std;
 
int n, t;
long long ans = 0;
priority_queue<int> Q;
 
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &t);
		Q.push(t);
		ans += Q.top() - t;
		Q.pop(); Q.push(t);
	}
	printf("%lld", ans);
	return 0;
}
