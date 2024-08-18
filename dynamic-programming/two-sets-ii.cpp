#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long f[502][65000];
int n;
long long modulo(long long x,long long y)
{
    int xm=1,xn=0,q,r,xr;
    while (y)
    {
        q=x/y;
        r=x%y;xr=xm-q*xn;
        x=y;xm=xn;
        y=r;xn=xr;
    }
    xm%=mod; if (xm<0) xm+=mod; /////////////
    return xm;
}
long long ans(int i,int s) {
    if (f[i][s]+1) {
        return f[i][s];
    }
    if (i>n) {
        if (s*4-n*(n+1)) {
            return 0;
        }
        return 1;
    }
    f[i][s]=ans(i+1,s)%mod;
    if (s+i<=n*(n+1)/4) {
        f[i][s]+=ans(i+1,s+i);
        f[i][s]%=mod;
    }
    return f[i][s];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    memset(f,255,sizeof(f));
    cin>>n;
    cout<<ans(1,0)*modulo(2,mod)%mod;
}
