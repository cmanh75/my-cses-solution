#include <bits/stdc++.h>
using namespace std;
int n,a[5005],k;
long long s[5005],dp[3003][3003];
struct line {
	int a;
	long long b;
	long long get_value(int x) {
		return 1ll*a*x+b;
	}
	bool bad_line(line z,line t) {
		return (double)(b-z.b)/(z.a-a)<=(double)(t.b-z.b)/(z.a-t.a);
	}
};
struct cht {
	vector <line> s;
	void add_line(line nw) {
		while (s.size()>1 && nw.bad_line(s[s.size()-2],s.back())) {
			s.pop_back();
		}
		s.push_back(nw);
	}
	long long bs(int x) {
		int l=0,r=s.size()-2;
		long long ans=s.back().get_value(x);
		while (l<=r) {
			int mid=(l+r)/2;
			if (s[mid].get_value(x)>=s[mid+1].get_value(x)) {
				l=mid+1;
				ans=s[mid+1].get_value(x);
			}
			else {
				r=mid-1;
				ans=s[mid].get_value(x);
			}
		}
		return ans;
	}
};
int main() {
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for (int i=1;i<=n;i++) {
		dp[i][1]=s[i]*s[i];
	}
	for (int j=2;j<=k;j++) {
		cht w;
    line z = {-2*s[j-1],s[j-1]*s[j-1]+dp[j-1][j-1]};
		w.add_line(z);
		for (int i=j;i<=n;i++) {
			dp[i][j]=w.bs(s[i])+s[i]*s[i];
      line z = {-2*s[i],s[i]*s[i]+dp[i][j-1]};
			w.add_line(z);
		}
	}
	cout<<dp[n][k];
}
