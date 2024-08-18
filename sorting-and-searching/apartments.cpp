#include<bits/stdc++.h>
using namespace std;
long long i,n,ans,a[1000009],b[1000009],j,m,k;
int main() {
    cin>>m>>n>>k;
    for (i=1;i<=m;i++) {
        cin>>a[i];
    }
    for (i=1;i<=n;i++) {
        cin>>b[i];
    }
    sort (a+1,a+m+1);
    sort (b+1,b+n+1);
    i=1;
    j=1;
    while (i<=m&&j<=n) {
        if (abs(a[i]-b[j])<=k) {
            ans++;
            i++;
            j++;
        }
        if (abs(a[i]-b[j])>k&&a[i]>b[j]) {
            j++;
            continue;
        }
        if (abs(a[i]-b[j])>k&&b[j]>a[i]) {
            i++;
        }
    }
    cout<<ans;
}
