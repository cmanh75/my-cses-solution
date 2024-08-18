#include<bits/stdc++.h>
using namespace std;
char c;
int f[1009][1009],x,y,z,t,q,n;
int ans(int x,int y,int z,int t) {
    return f[z][t]-f[x-1][t]-f[z][y-1]+f[x-1][y-1];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>c;
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+((c=='*')?1:0);
        }
    }
    while (q--) {
        cin>>x>>y>>z>>t;
        cout<<ans(x,y,z,t)<<"\n";
    }
}