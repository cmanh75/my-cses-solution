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
const int N=500005;
const int M=1000005;
const int moh=1e9+3;
const ll mod=998244353;
const int base=311;
const int oi=1e9;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,a[N],q;
struct itree {
    ll p,s,v,t;
    itree() {
        p=0,s=0,v=0,t=0;
    }
    itree(ll _p,ll _s,ll _v,ll _t) {
        p=_p,s=_s,v=_v,t=_t;
    }
}it[N*4];
itree cob(itree x,itree y) {
    itree z;
    z.v=max({x.v,y.v,x.s+y.p});
    z.p=max(x.p,x.t+y.p);
    z.s=max(y.s,y.t+x.s);
    z.t=x.t+y.t;
    return z;
}
void build(int i,int l,int r) {
    if (l==r) {
        int e=max(0,a[l]);
        it[i]={e,e,e,a[l]};
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    it[i]=cob(it[i*2],it[i*2+1]);
}
void update(int i,int l,int r,int p,int v) {
    if (l>p||r<p) {
        return;
    }
    if (l==r) {
        int e=max(0,v);
        it[i]={e,e,e,v};
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,p,v);
    update(i*2+1,mid+1,r,p,v);
    it[i]=cob(it[i*2],it[i*2+1]);
}
void solve() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    build(1,1,n);
    while (q--) {
        int x,y;
        cin>>x>>y;
        update(1,1,n,x,y);
        cout<<it[1].v<<"\n";
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