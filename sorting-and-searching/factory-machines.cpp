#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000009],ans;
bool check(long long x) {
    long long t=0;
    for (int i=1;i<=n;i++) {
        t+=x/a[i];
        if (t>=k) {
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    long long l=0,r=1e18;
    while (l<=r) {
        long long mid=(l+r)/2;
        if (check(mid)) {
            ans=mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    cout<<ans;
}
