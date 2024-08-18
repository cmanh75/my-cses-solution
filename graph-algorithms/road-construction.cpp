#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,lab[1000009],ans;
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
    int mi=1e9;
    ans=n;
    for (int i=1;i<=m;i++) {
        cin>>x>>y;
        int u=findset(x);
        int v=findset(y);
        if (u!=v) {
            lab[u]+=lab[v];
            mi=min(lab[u],mi);
            lab[v]=u;
            ans--;
        }
        cout<<ans<<" "<<-mi<<"\n";
    }
}