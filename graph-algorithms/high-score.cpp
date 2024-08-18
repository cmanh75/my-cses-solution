#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int n,m,x,y,z,l[1000009],d[1000009];
long long dis[1000009];
vector <tuple<int,int,int>> e;
vector <int> a[1000009],s[10000009];
void dfs(int i) {
    d[i]=1;
    for (int j : a[i]) {
        if (!d[j]) {
            dfs(j);
        }
    }
}
void dfs1(int i) {
    l[i]=1;
    for (int j : s[i]) {
        if (!l[j]) {
            dfs1(j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        cin>>x>>y>>z;
        a[x].push_back(y);
        s[y].push_back(x);
        e.push_back({x,y,z});
    }
    dfs(1);
    dfs1(n);
    for (int i=1;i<=n;i++) {
        dis[i]=-1e15;
    }
    dis[1]=0;
    for (int i=1;i<=n+1;i++) {
        for (auto [x,y,z] : e) {
            if (dis[y]<dis[x]+z) {
                dis[y]=dis[x]+z;
                if (i==n+1&&l[y]&&d[y]) {
                    cout<<"-1";
                    return 0;
                }
            }
        }
    }
    cout<<dis[n];
}