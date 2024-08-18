#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef pair<ll,pii> plii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pil> vil;
typedef vector<piii> viii;
typedef vector<pli> vli;
typedef vector<ll> vl;
const int N=200001;
const int M=1200000;
const int moh=1e9+3;
const ll mod=1e9+7;
const int base=311;
const int oi=2e9;
const ll oo=1e13;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int m,n,deg[N],d[N];
vi ans;
vii a[N];
void dfs(int i) {
    while (a[i].size()) {
        pii z=a[i].back();
        a[i].pob();
        if (!d[z.se]) {
            d[z.se]=1;
            dfs(z.fi);
        }
    }
    ans.pb(i);
}
void solve() {
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        a[x].pb(mp(y,i));
        a[y].pb(mp(x,i));
        deg[x]++;
        deg[y]++;
    }
    for (int i=1;i<=n;i++) {
        if (deg[i]&1) {
            cout<<"IMPOSSIBLE";
            return;
        }
    }
    dfs(1);
    if (ans.size()!=m+1) {
        cout<<"IMPOSSIBLE";
        return;
    }
    for (int j : ans) {
        cout<<j<<" ";
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
