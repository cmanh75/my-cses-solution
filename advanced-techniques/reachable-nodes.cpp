#pragma GCC target("popcnt")
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
const int N=5e4+5;
const int M=2e5;
const ll mod=1e9+7;
const int moh=1e9+3;
const int base=311;
const int oi=2e9;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,m,d[N];
bitset <N> f[N];
vi a[N];
void dfs(int i) {
    d[i]=1;
    f[i].set(i);
    for (int j : a[i]) {
        if (!d[j]) {
            dfs(j);
        }
        f[i]|=f[j];
    }
}
void solve() {
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    for (int i=1;i<=n;i++) {
        if (!d[i]) {
            dfs(i);
        }
    }
    for (int i=1;i<=n;i++) {
        cout<<f[i].count()<<" ";
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
