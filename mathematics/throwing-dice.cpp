#include<bits/stdc++.h>
using namespace std;
long long n;
struct matrix {
    long long e[6][6];
};
matrix a={1,2,4,8,16,32},b;
const long long mod=1e9+7;
matrix operator * (matrix a,matrix b) {
    matrix r;
    for (int i=0;i<6;i++) {
        for (int j=0;j<6;j++) {
            r.e[i][j]=0;
            for (int k=0;k<6;k++) {
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
    if (n<7) {
        cout<<a.e[0][n-1];
        return 0;
    }
    for (int i=0;i<5;i++) {
        b.e[i][5]=1;
        b.e[i+1][i]=1;
    }
    b.e[5][5]=1;
    n-=6;
    a=a*ans(b,n);
    cout<<a.e[0][5];
}