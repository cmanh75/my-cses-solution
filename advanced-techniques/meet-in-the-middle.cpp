#include<bits/stdc++.h>
#define pa pair <int,int>
#define fi first
#define se second
using namespace std;
int n,a[1000009],m;
long long ans;
vector <long long> b,c;
void cal(int i,long long r) {
    if (i>n/2) {
        b.push_back(r);
        return;
    }
//    if (r>m) {
//        return;
//    }
    cal(i+1,r+a[i]);
    cal(i+1,r);
}
void tim(int i,long long r) {
    if (i>n) {
        c.push_back(r);
        return;
    }
//    if (r>m) {
//        return;
//    }
    tim(i+1,r+a[i]);
    tim(i+1,r);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    cal(1,0);
    tim(n/2+1,0);
    sort(c.begin(),c.end());
    for (long long j : b) {
        long long r=m-j;
        int u=lower_bound(c.begin(),c.end(),r)-c.begin();
        int o=upper_bound(c.begin(),c.end(),r)-c.begin();
        ans+=o-u;
    }
    cout<<ans;
}
