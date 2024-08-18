#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,ans;
long long po[2000009],f[2000009],p,cs;
const long long mod=1e9+3;
long long geth(int x,int y) {
    return (f[y]-f[x-1]*po[y-x+1]+mod*mod)%mod;
}
bool check(int i) {
    int l=1,r=n,res=0;
    while (l<=r) {
        int mid=(l+r)/2;
        if (geth(i,i+mid-1)!=geth(cs,cs+mid-1)) {
            r=mid-1;
        }
        else {
            l=mid+1;
            res=mid;
        }
    }
    return (s[i+res]<s[cs+res]);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>s;
    n=s.size();
    s=" "+s+s;
    po[0]=1;
    for (int i=1;i<=n*2;i++) {
        f[i]=(f[i-1]*311+s[i]-'a')%mod;
        po[i]=po[i-1]*311;
        po[i]%=mod;
    }
    cs=1;
    for (int i=2;i<=n;i++) {
        if (check(i)) {
            cs=i;
        }
    }
    for (int i=cs;i<cs+n;i++) {
        cout<<s[i];
    }
}