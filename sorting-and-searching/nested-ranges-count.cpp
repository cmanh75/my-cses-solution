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
typedef pair<pii,int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pil> vil;
typedef vector<piii> viii;
typedef vector<pli> vli;
typedef vector<ll> vl;
const int N=200005;
const int M=5005;
const int moh=1e9+3;
const ll mod=1e9+7;
const int base=311;
const int oi=2e9;
const ll oo=4e18;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,ans[N],bit[N*2],m,res[N];
piii a[N];
vi s;
map <int,int> pos;
bool cmp(piii a,piii b) {
    if (a.fi.fi==b.fi.fi) {
        return a.fi.se>b.fi.se;
    }
    return a.fi.fi<b.fi.fi;
}
void update(int x,int v) {
    for (;x;x&=(x-1)) {
        bit[x]+=v;
    }
}
int get(int x) {
    int res=0;
    for (;x<=m;x+=(x&-x)) {
        res+=bit[x];
    }
    return res;
}
void updata(int x,int v) {
    for (;x<=m;x+=(x&-x)) {
        bit[x]+=v;
    }
}
int gea(int x) {
    int res=0;
    for (;x;x-=(x&-x)) {
        res+=bit[x];
    }
    return res;
}
bool cma(piii a,piii b) {
    if (a.fi.fi==b.fi.fi) {
        return a.fi.se<b.fi.se;
    }
    return a.fi.fi>b.fi.fi;
}
void solve() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].fi.fi>>a[i].fi.se;
        s.pb(a[i].fi.fi);
        s.pb(a[i].fi.se);
        a[i].se=i;
    }
    sort(s.begin(),s.end());
    s.resize(distance(s.begin(),unique(s.begin(),s.end())));
    m=s.size();
    for (int i=0;i<m;i++) {
        pos[s[i]]=i+1;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++) {
        int u=get(pos[a[i].fi.se]);
        ans[a[i].se]=u;
        update(pos[a[i].fi.se],1);
    }
    for (int i=1;i<=m;i++) {
        bit[i]=0;
    }
    sort(a+1,a+n+1,cma);
    for (int i=1;i<=n;i++) {
        int u=gea(pos[a[i].fi.se]);
        res[a[i].se]=u;
        updata(pos[a[i].fi.se],1);
    }
    for (int i=1;i<=n;i++) {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
    for (int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
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
