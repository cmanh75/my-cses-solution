#include<bits/stdc++.h>
using namespace std;
long long i,n,a[1001],f[1000001],t,j;
int main() {
    cin>>n>>t;
    for (i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (i=1;i<=t;i++) {
        f[i]=1e9;
    }
    for (i=0;i<=t;i++) {
        for (j=1;j<=n;j++) {
            if (i+a[j]<=t) {
                f[i+a[j]]=min(f[i+a[j]],f[i]+1);
            }
        }
    }
    if (f[t]==1e9) {
        cout<<"-1";
        return 0;
    }
    cout<<f[t];
}
