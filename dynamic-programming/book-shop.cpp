#include<bits/stdc++.h>
using namespace std;
long long n,p,a[100009],b[100009],f[1000009],s=0,ans;
int main() {
    cin>>n>>p;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++) {
        cin>>b[i];
    }
    f[0]=1;
    ans=1;
    for (int i=1;i<=n;i++) {
        for (int j=p-a[i];j>=0;j--) {
            if (f[j]) {
                f[j+a[i]]=max(f[j+a[i]],f[j]+b[i]);
                ans=max(ans,f[j+a[i]]);
            }
        }
    }
    cout<<ans-1;
}
