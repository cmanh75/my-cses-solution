#include<bits/stdc++.h>
using namespace std;
long long i,n,x,u,ans,a[10000009];
int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    u=a[n/2+(n%2!=0)];
    for (i=1;i<=n;i++) {
        ans+=abs(a[i]-u);
    }
    cout<<ans;
}
