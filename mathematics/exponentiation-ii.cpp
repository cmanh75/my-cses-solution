#include<bits/stdc++.h>
using namespace std;
long long a,b,c,q;
const long long mo=1e9+7;
long long mu(long long a,long long b,long long mod) {
    if (b==0) {
        return 1;
    }
    if (b==1) {
        return a;
    }
    long long t=mu(a,b/2,mod);
    if (b&1) {
        return (t*t)%mod*a%mod;
    }
    return t*t%mod;
}
void solve() {
    cin>>a>>b>>c;
    cout<<mu(a,mu(b,c,mo-1),mo)<<"\n";
}
int main() {
    for (cin>>q;q--;) {
        solve();
    }
}
