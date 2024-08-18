#include<bits/stdc++.h>
using namespace std;
int ans,a[1000009],n;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ans=1;
    for (int i=2;i<=n;i++) {
        if (a[i]!=a[i-1]) {
            ans++;
        }
    }
    cout<<ans;
}
