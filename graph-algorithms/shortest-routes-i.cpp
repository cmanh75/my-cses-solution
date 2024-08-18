#include<bits/stdc++.h>
#define pa pair <long long,long long>
#define fi first
#define se second
using namespace std;
int n,m,x,y,z;
long long d[1000009];
vector <pa> a[1000009];
void dijkstra(int x) {
    for (int i=1;i<=n;i++) {
        d[i]=1e18;
    }
    d[x]=0;
    priority_queue <pa> q;
    q.push({0,x});
    while (q.size()) {
        long long u=-q.top().fi;
        int v=q.top().se;
        q.pop();
        if (d[v]!=u) {
            continue;
        }
        for (auto j : a[v]) {
            if (d[j.fi]>d[v]+j.se) {
                d[j.fi]=d[v]+j.se;
                q.push({-d[j.fi],j.fi});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        cin>>x>>y>>z;
        a[x].push_back({y,z});
    }
    dijkstra(1);
    for (int i=1;i<=n;i++) {
        cout<<d[i]<<" ";
    }
}
