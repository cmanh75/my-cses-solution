#include<bits/stdc++.h>
using namespace std;
bitset <60> s;
long long f[1000009],n,ans;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    f[1]=1;
    n*=2;
    s=n;
    for (int i=2;i<=59;i++) {
        f[i]=f[i-1]*2+(1ll<<(i-1));
    }
    int ok=0;
    for (int i=59;i>=1;i--) {
        if (s[i]==1) {
            ans+=f[i-1]+ok*(1ll<<(i-1));
            ok++;
        }
    }
    ans+=s.count();
    cout<<ans;
}
