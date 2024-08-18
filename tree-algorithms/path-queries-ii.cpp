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
int n,it[N*5],nc[N],head[N],point[N],o=0,chain=0,lca[N][30],h[N],id[N],q,w[N],pos[N];
vi a[N];
void dfs(int i,int p) {
    nc[i]=1;
    for (int j : a[i]) {
        if (j-p) {
            h[j]=h[i]+1;
            lca[j][0]=i;
            dfs(j,i);
            nc[i]+=nc[j];
        }
    }
}
void hld(int i,int p) {
    if (!head[chain]) {
        head[chain]=i;
    }
    id[i]=chain;
    point[i]=++o;
    int ma=0,cs=0;
    for (int j : a[i]) {
        if (j-p) {
            if (ma<nc[j]) {
                cs=j;
                ma=nc[j];
            }
        }
    }
    if (cs) {
        hld(cs,i);
    }
    for (int j : a[i]) {
        if (j-p&&j-cs) {
            chain++;
            hld(j,i);
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
void build(int i,int l,int r) {
    if (l==r) {
        pos[l]=i;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
}
void updateit(int x,int y) {
    it[x]=y;
    x/=2;
    while (x) {
        it[x]=max(it[x*2],it[x*2+1]);
        x/=2;
    }
}
int ansit(int i,int l,int r,int L,int R) {
    if (l>R||r<L) {
        return -oi;
    }
    if (l>=L&&r<=R) {
        return it[i];
    }
    int mid=(l+r)/2;
    return max(ansit(i*2,l,mid,L,R),ansit(i*2+1,mid+1,r,L,R));
}
int ans(int x,int z) {
    int res=0;
    while (1) {
        if (id[x]-id[z]) {
            res=max(res,ansit(1,1,n,point[head[id[x]]],point[x]));
        }
        else {
            res=max(res,ansit(1,1,n,point[z],point[x]));
            break;
        }
        x=lca[head[id[x]]][0];
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
    h[1]=1;
    dfs(1,-1);
    hld(1,-1);
    for (int i=1;i<=log2(n);i++) {
        for (int j=1;j<=n;j++) {
            lca[j][i]=lca[lca[j][i-1]][i-1];
        }
    }
    build(1,1,n);
    for (int i=1;i<=n;i++) {
        updateit(pos[point[i]],w[i]);
    }
    while (q--) {
        int c,x,y;
        cin>>c>>x>>y;
        if (c==1) {
            updateit(pos[point[x]],y);
        }
        else {
            int z=lcaa(x,y);
            cout<<max(ans(x,z),ans(y,z))<<" ";
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
