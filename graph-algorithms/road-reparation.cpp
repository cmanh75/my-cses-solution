#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m,x,y,z,lab[1000009],ok;
struct iii {
    int z,x,y;
};
vector <iii> s;
bool cmp(iii m,iii n) {
    return m.z<n.z;
}
int findset(int x) {
    return (lab[x]<0)?x:lab[x]=findset(lab[x]);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        lab[i]=-1;
    }
    for (int i=1;i<=m;i++) {
        cin>>x>>y>>z;
        s.push_back({z,x,y});
    }
    sort(s.begin(),s.end(),cmp);
    for (int i=0;i<s.size();i++) {
        auto [z,x,y]=s[i];
        int u=findset(x);
        int v=findset(y);
        if (u!=v) {
            lab[u]=v;
            ans+=z;
        }
    }
    for (int i=1;i<=n;i++) {
        if (lab[i]==-1) {
            ok++;
        }
        if (ok>1) {
            cout<<"IMPOSSIBLE"<<"\n";
            return 0;
        }
    }
    cout<<ans;
}