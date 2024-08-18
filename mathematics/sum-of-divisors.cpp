#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int main() {
	ll n,ans=0;
	cin>>n;
	for (int i=1;i<=sqrt(n);i++) {
		ans=(ans+1ll*i*(n/i)%mod)%mod;
	}
	ll id=n/sqrt(n)+1,rd,ic;
	ll j=n/id,u;
	while (j>0) {
		rd=n%id;
		ic=id+rd/j;
		if (((id+ic)%2)==0) {
			u=(id+ic)/2%mod*((rd/j+1)%mod)%mod;
		}
		else {
			u=(rd/j+1)/2%mod*((id+ic)%mod)%mod;
		}
		ans=(ans+u*j%mod)%mod;
		id=ic+1;
		j--;
	}
	cout<<ans;
}
