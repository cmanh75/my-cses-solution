#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
const int N=2e5+5;
const int M=2e5;
const ll mod=1e9+7;
const int moh=1e9+3;
const int base=311;
const int oi=1e9;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,a[N],q;
ll it[N*8],lazy[N*8][4];
void down(int i,int l,int r) {
    if (lazy[i][2]) {
        it[i]=lazy[i][1]*(r-l+1)*1ll;
        lazy[i*2][2]=1;
        lazy[i*2][1]=lazy[i][1];
        lazy[i*2][0]=0;
        lazy[i*2+1][2]=1;
        lazy[i*2+1][1]=lazy[i][1];
        lazy[i*2+1][0]=0;
        lazy[i][2]=0;
    }
    it[i]+=lazy[i][0]*(r-l+1)*1ll;
    lazy[i*2][0]+=lazy[i][0];
    lazy[i*2+1][0]+=lazy[i][0];
    lazy[i][0]=0;
}
void build(int i,int l,int r) {
    if (l==r) {
        it[i]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    it[i]=it[i*2]+it[i*2+1];
}
void update(int i,int l,int r,int L,int R,ll val,int c) {
    down(i,l,r);
    if (l>R||r<L) {
        return;
    }
    if (l>=L&&r<=R) {
        if (c==1) {
            lazy[i][0]+=val;
        }
        else {
            lazy[i][2]=1;
            lazy[i][1]=val;
            lazy[i][0]=0;
        }
        down(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,L,R,val,c);
    update(i*2+1,mid+1,r,L,R,val,c);
    it[i]=it[i*2]+it[i*2+1];
}
ll ans(int i,int l,int r,int L,int R) {
    down(i,l,r);
    if (l>R||r<L) {
        return 0;
    }
    if (l>=L&&r<=R) {
        return it[i];
    }
    int mid=(l+r)/2;
    return ans(i*2,l,mid,L,R)+ans(i*2+1,mid+1,r,L,R);
}
void solve() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    build(1,1,n);
    while (q--) {
        int c,x,y,z;
        cin>>c>>x>>y;
        if (c<3) {
            cin>>z;
            update(1,1,n,x,y,z,c);
        }
        else {
            cout<<ans(1,1,n,x,y)<<"\n";
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
