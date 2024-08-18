#include<bits/stdc++.h>
using namespace std;
long long n,ans,f[100009][109],a[1000009],m;
const long long mod=1e9+7;
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    if (a[1]) {
        f[1][a[1]]=1;
    }
    else {
        for (int i=1;i<=m;i++) {
            f[1][i]=1;
        }
    }
    for (int i=2;i<=n;i++) {
        if (a[i]) {
            for (int j=a[i]-1;j<=a[i]+1;j++) {
                if (j>0&&j<=m) {
                    f[i][a[i]]+=f[i-1][j];
                    f[i][a[i]]%=mod;
                }
            }
        }
        else {
            for (int j=1;j<=m;j++) {
                for (int k=j-1;k<=j+1;k++) {
                    if (k>0&&k<=m) {
                        f[i][j]+=f[i-1][k];
                        f[i][j]%=mod;
                    }
                }
            }
        }
    }
    for (int i=1;i<=m;i++) {
        ans+=f[n][i];
        ans%=mod;
    }
    cout<<ans;
}
