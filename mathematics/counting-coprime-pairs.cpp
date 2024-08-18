#include <bits/stdc++.h>
using namespace std;
int n,a[100005],l[1000005],d[1000005];
int main() {
	cin>>n;
	for (int i=2;i<=1000000;i++) {
		if (l[i]) continue;
		for (int j=i;j<=1000000;j+=i) {
			l[j]=i;
		}
	}
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	long long ans=1ll*n*(n-1)/2;
	for (int i=1;i<=n;i++) {
		vector <int> s;
		while (a[i]!=1) {
			s.push_back(l[a[i]]);
			int x=l[a[i]];
			while (a[i]%x==0) {
				a[i]/=x;
			}
		}
		int m=s.size();
		for (int j=1;j<(1<<m);j++) {
			int c=1;
			int u=__builtin_popcount(j);
			for (int k=0;k<m;k++) {
				if (j>>k&1) {
					c*=s[k];
				}
			}
			if (u&1) {
				ans-=d[c];
			}
			else {
				ans+=d[c];
			}
			d[c]++;
		}
	}
	cout<<ans<<"\n";
}
