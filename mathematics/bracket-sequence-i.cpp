#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll res=1,g=1;
int n;
const ll mod=1e9+7;
ll po(ll x,int k) {
    if (k==1) {
        return x;
    }
    ll t=po(x,k/2);
    if (k&1) {
        return t*t%mod*x%mod;
    }
    return t*t%mod;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    if (n&1) {
        cout<<"0";
        return 0;
    }
    n/=2;
    for (int i=n+2;i<=n*2;i++) {
        res*=(ll)i;
        res%=mod;
    }
    for (int i=1;i<=n;i++) {
        g*=(ll)i;
        g%=mod;
    }
    cout<<res*po(g,mod-2)%mod;
}
