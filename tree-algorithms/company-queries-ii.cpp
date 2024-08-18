#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
const int N=2e5+9;
const int mod=998244353;
const int moh=1e9+3;
const int base=311;
const int oi=2e9;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int n,lca[N][30],q,h[N];
vi a[N];
void dfs(int i,int p) {
    for (int j : a[i]) {
        if (j-p) {
            lca[j][0]=i;
            h[j]=h[i]+1;
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
void solve() {
    cin>>n>>q;
    for (int i=2;i<=n;i++) {
        int x;
        cin>>x;
        a[x].push_back(i);
        a[i].push_back(x);
    }
    h[1]=1;
    dfs(1,-1);
    for (int i=1;i<=log2(n);i++) {
        for (int j=1;j<=n;j++) {
            lca[j][i]=lca[lca[j][i-1]][i-1];
        }
    }
    while (q--) {
        int x,y;
        cin>>x>>y;
        cout<<lcaa(x,y)<<"\n";
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