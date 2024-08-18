#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long gt[1000009],f[1000009],n;
long long po(long long x) {
    if (x==1) {
        return gt[1000000];
    }
    long long t=po(x/2);
    if (x&1) {
        return (((t*t)%mod)*gt[1000000])%mod;
    }
    return (t*t)%mod;
}
long long th(long long a,long long b) {
    return ((gt[a]*f[b])%mod)*f[a-b]%mod;
}
int main() {
    cin>>n;
    gt[0]=1;
    for (int i=1;i<=1000000;i++) {
        gt[i]=gt[i-1]*i;
        gt[i]%=mod;
    }
    f[1000000]=po(mod-2);
    for (int i=999999;i>=0;i--) {
        f[i]=f[i+1]*(i+1);
        f[i]%=mod;
    }
    for (int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        cout<<th(x,y)<<"\n";
    }
}