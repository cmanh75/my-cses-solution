#include<bits/stdc++.h>
using namespace std;
long long m,n,a[1000009],x,ans,t;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>x;
        ans+=x;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) {
        t+=a[i];
        ans-=t;
    }
    cout<<ans;
}
