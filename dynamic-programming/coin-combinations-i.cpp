#include<bits/stdc++.h>
using namespace std;
long long i,n,a[1001],f[1000001],t,j;
int main() {
    cin>>n>>t;
    for (i=1;i<=n;i++) {
        cin>>a[i];
    }
    f[0]=1;
    for (i=0;i<=t;i++) {
        for (j=1;j<=n;j++) {
            if (i+a[j]<=t) {
                f[i+a[j]]+=f[i];
                f[i+a[j]]%=1000000007;
            }
        }
    }
    cout<<f[t];
}
