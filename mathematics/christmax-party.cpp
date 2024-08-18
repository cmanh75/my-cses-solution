#include<bits/stdc++.h>
using namespace std;
long long f[1000009],gt[1000009],ans;
int n;
const int mod=1e9+7;
long long po(int x) {
    if (x==1) {
        return gt[n];
    }
    long long t=po(x/2);
    if (x&1) {
        return t*t%mod*gt[n]%mod;
    }
    return t*t%mod;
}
long long th(int x,int y) {
    return gt[y]*f[x]%mod*f[y-x]%mod;
}
int main() {
    cin>>n;
    gt[0]=1;
    for (int i=1;i<=n;i++) {
        gt[i]=gt[i-1]*i;
        gt[i]%=mod;
    }
    f[n]=po(mod-2);
    for (int i=n-1;i>=0;i--) {
        f[i]=f[i+1]*(i+1);
        f[i]%=mod;
    }
    ans=gt[n];
    for (int i=1;i<=n;i++) {
        if (i&1) {
            ans+=mod-(th(i,n)*gt[n-i])%mod;
        }
        else {
            ans+=(th(i,n)*gt[n-i])%mod;
        }
        ans%=mod;
    }
    cout<<ans;
}
