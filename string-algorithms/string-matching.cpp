#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,t;
long long po[1000009],f[1000009],p;
const long long mod=1e9+3;
long long geth(int x,int y) {
    return (f[y]-f[x-1]*po[y-x+1]+mod*mod)%mod;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>s>>t;
    n=s.size();
    m=t.size();
    s=" "+s;
    t=" "+t;
    po[0]=1;
    for (int i=1;i<=n;i++) {
        f[i]=(f[i-1]*311+s[i]-'a')%mod;
        po[i]=po[i-1]*311;
        po[i]%=mod;
    }
    for (int i=1;i<=m;i++) {
        p=(p*311+t[i]-'a')%mod;
    }
    int ans=0;
    for (int i=1;i<=n-m+1;i++) {
        if (geth(i,i+m-1)==p) {
            ans++;
        }
    }
    cout<<ans;
}
