#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long p[1000009],ri[1000009],sum=1,k[1000009],le[1000009],n,prod=1,z,num=1;
long long power(long long x,long long z) {
    if (z==1) {
        return x;
    }
    long long t=power(x,z/2);
    if (z&1) {
        return ((t*t)%mod*x)%mod;
    }
    return t*t%mod;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>p[i]>>k[i];
    }
    le[0]=1;
    ri[n+1]=1;
    for (int i=1;i<=n;i++) {
        le[i]=le[i-1]*(k[i]+1)%(mod-1);
    }
    for (int i=n;i>=1;i--) {
        ri[i]=ri[i+1]*(k[i]+1)%(mod-1);
    }
    for (int i=1;i<=n;i++) {
        num=num*(k[i]+1)%mod;
        sum=sum*((power(p[i],k[i]+1)-1+mod)%mod*power(p[i]-1,mod-2)%mod)%mod;
    }
    for (int i=1;i<=n;i++) {
        long long r=(k[i]*(k[i]+1)/2)%(mod-1);
        z=(le[i-1]*ri[i+1]%(mod-1))*r%(mod-1);
        prod=prod*power(p[i],z)%mod;
    }
    cout<<num<<" "<<sum<<" "<<prod;
}
