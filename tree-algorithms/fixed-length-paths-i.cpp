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
const int N=4e5+9;
const int mod=998244353;
const int moh=1e9+3;
const int base=311;
const int oi=2e9;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,nc[N],f[N],d[N],k,ma;
vi a[N];
ll ans=0;
void dfs(int i,int p) {
    nc[i]=1;
    for (int j : a[i]) {
        if (j-p&&!d[j]) {
            dfs(j,i);
            nc[i]+=nc[j];
        }
    }
}
int f_cent(int i,int p,int n) {
    for (int j : a[i]) {
        if (j-p&&nc[j]*2>n&&!d[j]) {
            return f_cent(j,i,n);
        }
    }
    return i;
}
void cal(int i,int p,int z) {
    ans+=f[k-z];
    for (int j : a[i]) {
        if (j-p&&!d[j]&&z<k) {
            cal(j,i,z+1);
        }
    }
}
void update(int i,int p,int z) {
    f[z]++;
    ma=max(ma,z);
    for (int j : a[i]) {
        if (j-p&&!d[j]&&z<k) {
            update(j,i,z+1);
        }
    }
}
void centroid(int i) {
    dfs(i,-1);
    int u=f_cent(i,-1,nc[i]);
    d[u]=1;
    for (int j=1;j<=ma;j++) {
        f[j]=0;
    }
    ma=0;
    f[0]=1;
    for (int j : a[u]) {
        if (!d[j]) {
            cal(j,u,1);
            update(j,u,1);
        }
    }
    for (int j : a[u]) {
        if (!d[j]) {
            centroid(j);
        }
    }
}
void solve() {
    cin>>n>>k;
    for (int i=1;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    centroid(1);
    cout<<ans;
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
