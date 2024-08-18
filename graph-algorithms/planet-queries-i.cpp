#include<bits/stdc++.h>
using namespace std;
int n,q,lca[200009][32],x,y;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>lca[i][0];
    }
    for (int i=1;i<=30;i++) {
        for (int j=1;j<=n;j++) {
            lca[j][i]=lca[lca[j][i-1]][i-1];
        }
    }
    while (q--) {
        cin>>x>>y;
        for (int i=30;i>=0;i--) {
            if ((1<<i)<=y) {
                x=lca[x][i];
                y-=(1<<i);
            }
        }
        cout<<x<<"\n";
    }
}