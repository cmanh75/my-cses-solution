#include<bits/stdc++.h>
using namespace std;
long long i,n,a[1000000],ans,x,y,t;
void solve() {
    ans=(n*n)*(n*n-1)/2;
    ans-=4*(n-1)*(n-2);
    cout<<ans<<"\n";
}
int main() {
    for (cin>>t,n=1;n<=t;n++) {
        solve();
    }
}