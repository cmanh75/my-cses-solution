#include<bits/stdc++.h>
using namespace std;
int q,n,d[1000009];
void solve() {
    cin>>n;
    if (n==1) {
        cout<<"1"<<"\n";
        return;
    }
    int ans=1,u=0,o=0;
    while (d[n]) {
        if (d[n]!=u) {
            ans*=(o+1);
            o=1;
        }
        else {
            o++;
        }
        u=d[n];
        n/=d[n];
    }
    if (n==u) {
        o++;
    }
    else {
        ans*=(o+1);
        o=1;
    }
    ans*=(o+1);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>q;
    for (int i=2;i<=1000;i++) {
        if (!d[i]) {
            for (int j=i*i;j<=1000000;j+=i) {
                if (!d[j]) {
                    d[j]=i;
                }
            }
        }
    }
    while (q--) {
        solve();
    }
}
