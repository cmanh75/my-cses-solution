#include<bits/stdc++.h>
using namespace std;
int q,m,n,bit[1009][1009],x,y,z,t,c;
char a[1009][1009];
void update(int x,int y,int val) {
    for (;x<=n;x+=(x&-x)) {
        for (int z=y;z<=n;z+=(z&-z)) {
            bit[x][z]+=val;
        }
    }
}
int ans(int x,int y) {
    int res=0;
    for (;x>0;x&=(x-1)) {
        for (int z=y;z>0;z&=(z-1)) {
            res+=bit[x][z];
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            if (a[i][j]=='*') {
                update(i,j,1);
            }
        }
    }
    while (q--) {
        cin>>c>>x>>y;
        if (c==1) {
            if (a[x][y]=='.') {
                update(x,y,1);
                a[x][y]='*';
            }
            else {
                a[x][y]='.';
                update(x,y,-1);
            }
        }
        else {
            cin>>z>>t;
            cout<<ans(z,t)-ans(x-1,t)-ans(z,y-1)+ans(x-1,y-1)<<"\n";
        }
    }
}