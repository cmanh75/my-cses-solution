#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long gt[1000009],f[1000009],n,ans=1,d[1000];
string s;
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
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
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
    cin>>s;
    n=s.size();
    for (int i=0;i<s.size();i++) {
        d[s[i]]++;
    }
    for (int i='a';i<='z';i++) {
        ans*=th(n,d[i]);
        ans%=mod;
        n-=d[i];
    }
    cout<<ans;
}