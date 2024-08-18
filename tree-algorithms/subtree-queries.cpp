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
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,w[N],in[N],out[N],o,q;
vi a[N];
ll bit[N*2];
void dfs(int i,int p) {
    in[i]=++o;
    for (int j : a[i]) {
        if (j-p) {
            dfs(j,i);
        }
    }
    out[i]=++o;
}
void update(int x,ll val) {
    for (;x<=o;x+=(x&-x)) {
        bit[x]+=val;
    }
}
ll ans(int x) {
    ll res=0;
    for (;x;x&=(x-1)) {
        res+=bit[x];
    }
    return res;
}
void solve() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>w[i];
    }
    for (int i=1;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,-1);
    for (int i=1;i<=n;i++) {
        update(in[i]+1,w[i]);
    }
    while (q--) {
        int c,x,y;
        cin>>c>>x;
        if (c==1) {
            cin>>y;
            update(in[x]+1,y-w[x]);
            w[x]=y;
        }
        else {
            cout<<ans(out[x])-ans(in[x])<<"\n";
        }
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
