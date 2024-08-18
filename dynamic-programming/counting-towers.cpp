#include<bits/stdc++.h>
using namespace std;
long long f[1000009][7];
int q,n,ma,a[1000009];
const int mod=1e9+7;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>q;
    for (int i=1;i<=q;i++) {
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    f[1][1]=1;
    f[1][2]=1;
    for (int i=2;i<=ma;i++) {
        f[i][1]=(f[i-1][1]+f[i-1][2]+f[i-1][3]+f[i-1][4]+f[i-1][5]+f[i-1][6]);
        f[i][2]=(f[i-1][1]+f[i-1][2]+f[i-1][3]+f[i-1][4]+f[i-1][5]+f[i-1][6]);
        f[i][3]=(f[i-1][2]+f[i-1][3]);
        f[i][4]=(f[i-1][1]+f[i-1][4]+f[i-1][5]+f[i-1][6]);
        f[i][5]=(f[i-1][1]+f[i-1][4]+f[i-1][5]+f[i-1][6]);
        f[i][6]=(f[i-1][1]+f[i-1][4]+f[i-1][5]+f[i-1][6]);
        for (int j=1;j<=6;j++) {
            f[i][j]%=mod;
        }
    }
    for (int i=1;i<=q;i++) {
        int n=a[i];
        cout<<(f[n][1]+f[n][2]+f[n][3]+f[n][4]+f[n][5]+f[n][6])%mod<<"\n";
    }
}
