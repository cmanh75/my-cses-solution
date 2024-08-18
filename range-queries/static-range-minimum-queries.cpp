#include<bits/stdc++.h>
using namespace std;
int n,rmq[1000009][30],q,a[1000009],x,y;
const long long mod=1e9+7;
long long rmqu(int x,int u) {
    int o=log2(u);
    return min(rmq[x][o],rmq[x+u-(1<<o)][o]);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>rmq[i][0];
    }
    for (int i=1;i<=log2(n);i++) {
        for (int j=1;j<=n-(1<<i)+1;j++) {
            rmq[j][i]=min(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
        }
    }
    while (q--) {
        cin>>x>>y;
        cout<<rmqu(x,y-x+1)<<"\n";
    }
}