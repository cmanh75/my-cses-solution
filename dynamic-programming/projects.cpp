#include<bits/stdc++.h>
using namespace std;
int n;
struct iii {
    int x,y,z;
} a[1000009];
long long ans,dp[1000009];
vector <iii> s;
bool ss(iii m,iii n) {
    if (m.x==n.x) {
        return m.y<n.y;
    }
    return m.x<n.x;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].x>>a[i].y>>a[i].z;
        s.push_back({a[i].x,-1,i});
        s.push_back({a[i].y,1,i});
    }
    sort(s.begin(),s.end(),ss);
    ans=0;
    for (int i=0;i<s.size();i++) {
        if (s[i].y<0) {
            dp[s[i].z]=ans+a[s[i].z].z;
        }
        else {
            ans=max(ans,dp[s[i].z]);
        }
    }
    cout<<ans;
}
