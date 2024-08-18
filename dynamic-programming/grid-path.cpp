#include<bits/stdc++.h>
using namespace std;
long long n,f[1009][1009];
const long long mod=1e9+7;
char a[1009][1009];
long long cal(int i,int j) {
    if (f[i][j]+1) {
        return f[i][j];
    }
    if (i<1||i>n||j<1||j>n||a[i][j]=='*') {
        return 0;
    }
    if (i==n&&j==n) {
        return 1;
    }
    f[i][j]=(cal(i+1,j)+cal(i,j+1))%mod;
    return f[i][j];
}
int main() {
    memset(f,255,sizeof(f));
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    cout<<cal(1,1);
}
