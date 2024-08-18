#include<bits/stdc++.h>
using namespace std;
long long n,f[1000009],i,j;
int main() {
    cin>>n;
    f[1]=1;
    f[2]=2;
    f[3]=4;
    f[4]=8;
    f[5]=16;
    f[6]=32;
    for (i=7;i<=n;i++) {
        for (j=i-1;j>=i-6;j--) {
            f[i]+=f[j];
        }
        f[i]%=1000000007;
    }
    cout<<f[n];
}
