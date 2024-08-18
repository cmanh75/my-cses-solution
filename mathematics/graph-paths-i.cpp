#include<bits/stdc++.h>
using namespace std;
struct matrix {
    long long e[102][102];
} e,w;
int n,m,k,x,y;
const long long mod=1e9+7;
matrix operator * (matrix a,matrix b) {
    matrix c;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            c.e[i][j]=0;
            for (int k=0;k<n;k++) {
                c.e[i][j]+=(a.e[i][k]*b.e[k][j])%mod;
                c.e[i][j]%=mod;
            }
        }
    }
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        cin>>x>>y;
        e.e[x-1][y-1]++;
    }
    w=e;
    for (k--;k;k>>=1,w=w*w) {
        if (k&1) {
            e=e*w;
        }
    }
    cout<<e.e[0][n-1];
}
