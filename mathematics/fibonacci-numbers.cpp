#include<bits/stdc++.h>
using namespace std;
long long n;
struct matrix {
    long long e[2][2];
};
matrix a,b;
const long long mod=1e9+7;
matrix operator * (matrix a,matrix b) {
    matrix r;
    for (int i=0;i<2;i++) {
        for (int j=0;j<2;j++) {
            r.e[i][j]=0;
            for (int k=0;k<2;k++) {
                r.e[i][j]+=a.e[i][k]*b.e[k][j];
                r.e[i][j]%=mod;
            }
        }
    }
    return r;
}
matrix ans(matrix c,long long n) {
    if (n==1) {
        return c;
    }
    matrix t=ans(c,n/2);
    if (n&1) {
        return (t*t)*c;
    }
    return t*t;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    a.e[0][1]=1;
    b.e[0][1]=1;
    b.e[1][0]=1;
    b.e[1][1]=1;
    if (n<2) {
        cout<<a.e[0][n];
        return 0;
    }
    n--;
    a=a*ans(b,n);
    cout<<a.e[0][1];
}