#include<bits/stdc++.h>
using namespace std;
long long s,ans,n,a[1000009],f[1000009],p,x;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    f[0]=1;
    for (int i=1;i<=n;i++) {
        cin>>x;
        s+=x+n*1000000009;
        s%=n;
        f[s]++;
    }
    for (int i=0;i<n;i++) {
        ans+=(f[i]-1)*f[i]/2;
    }
    cout<<ans;
}
