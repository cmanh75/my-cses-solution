#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
const int N=2e5+9;
const int oi=2e9;
const int mod=1e9+7;
const int moh=1e9+3;
const int base=311;
const ll oo=1e18;
const double eps=1e-9;
int a[N],q,n,o;
ll it[N*10],lazy[N*10][3];
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
void down(int i,int l,int r) {
    if (lazy[i][1]) {
        it[i]+=(ll)((ll)(r-l)*lazy[i][1]+lazy[i][0]*2)*(r-l+1)/2;
        lazy[i*2][1]+=lazy[i][1];
        lazy[i*2+1][1]+=lazy[i][1];
        int mid=(l+r)/2;
        lazy[i*2][0]+=lazy[i][0];
        lazy[i*2+1][0]+=lazy[i][0]+(ll)lazy[i][1]*(mid+1-l);
        lazy[i][1]=0;
        lazy[i][0]=0;
    }
}
void update(int i,int l,int r,int L,int R) {
    down(i,l,r);
    if (l>R||r<L) {
        return;
    }
    if (l>=L&&r<=R) {
        lazy[i][0]+=o;
        lazy[i][1]++;
        o+=r-l+1;
        down(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,L,R);
    update(i*2+1,mid+1,r,L,R);
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
        int c,x,y;
        cin>>c>>x>>y;
        if (c==1) {
            o=1;
            update(1,1,n,x,y);
        }
        else {
            cout<<ans(1,1,n,x,y)<<"\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    int test=1;
    while (test--) {
        solve();
    }
}