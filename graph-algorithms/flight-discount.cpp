#include<bits/stdc++.h>
#define pa pair <long long,int>
#define fi first
#define se second
using namespace std;
int n,m,x,y;
long long d[100009],w[100009],ans=1e18,z;
vector <pa> a[100009],b[100009];
vector <tuple<int,int,int>> e;
void dijkstra(int s,long long d[],vector <pa> a[]) {
    priority_queue <pa> q;
    q.push({0,s});
    for (int i=1;i<=n;i++) {
        d[i]=1e18;
    }
    d[s]=0;
    while (q.size()) {
        long long x;
        int y;
        tie(x,y)=q.top();
        q.pop();
        if (d[y]!=-x) {
            continue;
        }
        for (auto j : a[y]) {
            int u,v;
            tie(u,v)=j;
            if (d[y]+v<d[u]) {
                d[u]=d[y]+v;
                q.push({-d[u],u});
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
        b[y].push_back({x,z});
        e.push_back({x,y,z});
    }
    dijkstra(1,d,a);
    dijkstra(n,w,b);
    for (auto j : e) {
        tie(x,y,z)=j;
        ans=min(ans,d[x]+w[y]+z/2);
//        cout<<d[x]+w[y]+z/2<<"\n";
    }
    cout<<ans;
}
