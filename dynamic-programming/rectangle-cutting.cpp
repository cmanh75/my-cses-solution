#include<bits/stdc++.h>
using namespace std;
int ans=1e3,m,n,f[1009][1009];
int cal(int m,int n) {
    if (m==n) {
        return 0;
    }
    if (f[m][n]) {
        return f[m][n];
    }
    int res=1e3;
    for (int j=1;j<m;j++) {
        res=min(res,cal(j,n)+cal(m-j,n)+1);
    }
    for (int j=1;j<n;j++) {
        res=min(res,cal(m,j)+cal(m,n-j)+1);
    }
    f[m][n]=res;
    return res;
}
int main() {
    cin>>m>>n;
    if (m==n) {
        cout<<"0";
        return 0;
    }
    for (int i=1;i<m;i++) {
        ans=min(ans,cal(i,n)+cal(m-i,n)+1);
    }
    for (int i=1;i<n;i++) {
        ans=min(ans,cal(m,i)+cal(m,n-i)+1);
    }
    cout<<ans;
}
