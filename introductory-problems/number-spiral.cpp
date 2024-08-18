#include<bits/stdc++.h>
using namespace std;
long long i,n,a[1000000],ans,x,y,t;
void solve() {
    cin>>x>>y;
    ans=(max(x,y)-1)*(max(x,y)-1);
    if (x<y) {
        if (y%2!=0) {
            ans+=2*y-x;
        }
        else {
            ans+=x;
        }
    }
    else {
        if (x%2!=0) {
            ans+=y;
        }
        else {
            ans+=2*x-y;
        }
    }
    cout<<ans<<"\n";
}
int main() {
    for (cin>>t;t--;) {
        solve();
    }
}