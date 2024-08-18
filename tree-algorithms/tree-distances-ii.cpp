#include<bits/stdc++.h>
using namespace std;
long long n,x,y,f[1000009],r[1000009];
vector <int> a[1000009];
void cal(int i,int p,int k) {
    r[i]=1;
    for (int j : a[i]) {
        if (j!=p) {
            f[1]+=k;
            cal(j,i,k+1);
            r[i]+=r[j];
        }
    }
}
void dfs(int i,int p) {
    for (int j : a[i]) {
        if (j!=p) {
            int o=r[j];
            f[j]=f[i]-r[j]+n-r[j];
            dfs(j,i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<n;i++) {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    cal(1,-1,1);
    dfs(1,-1);
    for (int i=1;i<=n;i++) {
        cout<<f[i]<<" ";
    }
}