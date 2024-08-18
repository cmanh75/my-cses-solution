#include<bits/stdc++.h>
using namespace std;
long long i,n,a[1000000],ans,x,y,t;
vector <long long> setf,sets;
void solve() {
    cin>>n;
    ans=1;
    for (i=1;i<=n;i++) {
        ans=ans<<1;
        ans%=(1000000007);
    }
    cout<<ans;
}
int main() {
    solve();
}
