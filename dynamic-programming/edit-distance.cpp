#include<bits/stdc++.h>
using namespace std;
long long n,m,f[5009][5009];
string a,b;
int main() {
    cin>>a>>b;
    m=a.size();
    n=b.size();
    a=" "+a;
    b=" "+b;
    for (int i=1;i<=m;i++) {
        f[i][0]=i;
    }
    for (int i=1;i<=n;i++) {
        f[0][i]=i;
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            f[i][j]=min({f[i-1][j]+1,f[i][j-1]+1,f[i-1][j-1]+(a[i]!=b[j])});
        }
    }
    cout<<f[m][n];
}
