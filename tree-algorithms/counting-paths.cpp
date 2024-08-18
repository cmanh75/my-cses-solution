#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pil> vil;
typedef vector<pli> vli;
typedef vector<ll> vl;
typedef vector<piii> viii;
const int N=3e5+5;
const int M=2e5;
const ll mod=998244353;
const int moh=1e9+3;
const int base=311;
const int oi=1e9;
const ll oo=1e15;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,m,d[N],lca[N][30],h[N];
vi a[N];
void dfs(int i,int p) {
    for (int j : a[i]) {
        if (j-p) {
            h[j]=h[i]+1;
            lca[j][0]=i;
            dfs(j,i);
        }
    }
}
int lcaa(int x,int y) {
    if (h[x]>h[y]) {
        swap(x,y);
    }
    for (int i=log2(n);i>=0;i--) {
        if (h[lca[y][i]]>=h[x]) {
            y=lca[y][i];
        }
    }
    if (x==y) {
        return x;
    }
    for (int i=log2(n);i>=0;i--) {
        if (lca[x][i]-lca[y][i]) {
            x=lca[x][i];
            y=lca[y][i];
        }
    }
    return lca[x][0];
}
void cal(int i,int p) {
    for (int j : a[i]) {
        if (j-p) {
            cal(j,i);
        }
    }
    if (p+1) {
        d[p]+=d[i];
    }
}
void solve() {
    cin>>n>>m;
    for (int i=1;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    h[1]=1;
    dfs(1,-1);
    for (int i=1;i<=log2(n);i++) {
        for (int j=1;j<=n;j++) {
            lca[j][i]=lca[lca[j][i-1]][i-1];
        }
    }
    for (int i=1;i<=m;i++) {
        int x,y,z;
        cin>>x>>y;
        z=lcaa(x,y);
        d[x]++;
        d[y]++;
        d[z]--;
        d[lca[z][0]]--;
    }
    cal(1,-1);
    for (int i=1;i<=n;i++) {
        cout<<d[i]<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    int test=1;
    while (test--) {
        solve();
    }
}
