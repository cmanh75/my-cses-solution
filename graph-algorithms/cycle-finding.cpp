#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair <int,int> pa;
vector <int> a[1000009],ans;
vector <tuple<int,int,int>> e;
int n,m,x,y,par[1000009],cs,z,ok,l[1000009];
long long d[1000009];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        cin>>x>>y>>z;
        e.push_back({x,y,z});
    }
    for (int i=1;i<=n;i++) {
        d[i]=1e12;
    }
    d[1]=0;
    for (int i=1;i<=n+1;i++) {
        ok=0;
        for (auto [x,y,z] : e) {
            if (d[y]>d[x]+z) {
                ok=1;
                par[y]=x;
                cs=y;
                d[y]=d[x]+z;
            }
        }
    }
    if (!ok) {
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<=n;i++) {
        cs=par[cs];
    }
    cout<<"YES"<<"\n";
    while (!l[cs]) {
        ans.push_back(cs);
        l[cs]=1;
        cs=par[cs];
    }
    reverse(ans.begin(),ans.end());
    for (int j : ans) {
        cout<<j<<" ";
    }
    cout<<ans[0];
}
