#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
long long po[2000009],f[2000009],p,cs,g[2000009];
const long long mod=1e9+3;
long long gethf(int x,int y) {
    return (f[y]-f[x-1]*po[y-x+1]+mod*mod)%mod;
}
long long geths(int x,int y) {
    return (g[x]-g[y+1]*po[y-x+1]+mod*mod)%mod;
}
bool check(int x) {
    for (int i=1;i<=n-x+1;i++) {
        if (gethf(i,i+x-1)==geths(i,i+x-1)) {
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>s;
    n=s.size();
    s=" "+s;
    po[0]=1;
    for (int i=1;i<=n;i++) {
        f[i]=(f[i-1]*311+s[i]-'a')%mod;
        po[i]=po[i-1]*311;
        po[i]%=mod;
    }
    for (int i=n;i>=1;i--) {
        g[i]=(g[i+1]*311+s[i]-'a')%mod;
    }
    ans=1;
    int l=1,r=n/2;
    while (l<=r) {
        int mid=(l+r)/2;
        if (check(mid*2+1)) {
            l=mid+1;
            ans=max(ans,mid*2+1);
        }
        else {
            r=mid-1;
        }
    }
    l=1,r=n/2;
    while (l<=r) {
        int mid=(l+r)/2;
        if (check(mid*2)) {
            l=mid+1;
            ans=max(ans,mid*2);
        }
        else {
            r=mid-1;
        }
    }
    for (int i=1;i<=n;i++) {
        if (gethf(i,i+ans-1)==geths(i,i+ans-1)) {
            for (int j=i;j<i+ans;j++) {
                cout<<s[j];
            }
            break;
        }
    }
}
