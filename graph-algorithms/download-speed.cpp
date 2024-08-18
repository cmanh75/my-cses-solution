#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <pii> vii;
const int N=2e5+9;
const int mod=1e9+7;
const int moh=1e9+3;
const int base=311;
const int oi=2e9;
const ll oo=1e18;
const double eps=1e-9;
int n,m,trace[N],s,t;
ll c[1009][1009],f[1009][1009],ans,mi;
vector <int> a[N];
bool findpath() {
    queue <int> qu;
    qu.push(s);
    for (int i=1;i<=n;i++) {
        trace[i]=0;
    }
    trace[s]=1;
    mi=oo;
    while (qu.size()) {
        int x=qu.front();
        qu.pop();
        if (x==t) {
            return mi;
        }
        for (int j : a[x]) {
            if (f[x][j]<c[x][j]&&!trace[j]) {
                mi=min(mi,c[x][j]-f[x][j]);
                qu.push(j);
                trace[j]=x;
            }
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    s=1,t=n;
    for (int i=1;i<=m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[x].push_back(y);
        a[y].push_back(x);
        c[x][y]+=z;
    }
    while (findpath()) {
        int j,i=t;
        do {
            j=trace[i];
            f[j][i]+=mi;
            f[i][j]-=mi;
            i=j;
        } while (i-s);
        ans+=mi;
    }
    cout<<ans;
}