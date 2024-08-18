#include<bits/stdc++.h>
using namespace std;
int n,m;
long long g[1000009],f[1000009],ans;
const long long mod=1e9+7;
long long po(long long x,int y) {
    if (y<0) {
        return 0;
    }
    if (!y) {
        return 1;
    }
    if (y==1) {
        return x;
    }
    long long t=po(x,y/2);
    if (y&1) {
        return ((t*t%mod)*x)%mod;
    }
    return t*t%mod;
}
long long th(int x,int y) {
    return (((g[y]*f[x])%mod)*f[y-x])%mod;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    g[0]=1;
    for (int i=1;i<=max(m,n);i++) {
        g[i]=g[i-1]*i;
        g[i]%=mod;
    }
    f[max(m,n)]=po(g[max(m,n)],mod-2);
    for (int i=max(m,n)-1;i>=0;i--) {
        f[i]=(f[i+1]*(i+1));
        f[i]%=mod;
    }
    for (int i=0;i<n;i++) {
        if (n-i-1<=m-1) {
            ans+=(th(i,n)*th(n-i-1,m-1))%mod;
            ans%=mod;
//            cout<<ans<<"\n";
        }
//        cout<<ans<<"\n";
    }
    cout<<ans;
}