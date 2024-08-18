#include<bits/stdc++.h>
using namespace std;
int m;
typedef long long ll;
ll n,a[100],ans;
void cal(int i,int c,ll s) {
    if (i>m) {
        return;
    }
    ll z;
    cal(i+1,c,s);
    if (n/s>=a[i]) {
        z=s*a[i];
    }
    else {
        return;
    }
    if (c&1) {
        ans-=n/z;
    }
    else {
        ans+=n/z;
    }
    cal(i+1,c+1,z);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        cin>>a[i];
    }
    cal(1,0,1);
    cout<<ans;
}