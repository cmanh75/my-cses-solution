#include<bits/stdc++.h>
using namespace std;
long long n,a[1000009],ans,s[1000009],x;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>x;
    int j=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        while (s[i]-s[j]>x) {
            j++;
        }
        if (s[i]-s[j]==x) {
            ans++;
        }
    }
    cout<<ans;
}
