#include<bits/stdc++.h>
using namespace std;
long long i,n,x,mi,ans=-1e18,s;
int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        s+=x;
        ans=max(ans,s-mi);
        if (s<mi) {
            mi=s;
        }
    }
    cout<<ans;
}
