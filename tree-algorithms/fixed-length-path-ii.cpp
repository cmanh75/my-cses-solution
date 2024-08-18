#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <pii> vii;
const int N=2e5+9;
const int mod=1e9+7;
const int oi=2e9;
const int moh=1e9+3;
const int base=311;
const ll oo=1e18;
const double eps=1e-9;
int n,nc[N],bit[N],l,r,ma=0,d[N],mx;
vi a[N];
ll res=0;
void dfs(int i,int p) {
    nc[i]=1;
    for (int j : a[i]) {
        if (j-p&&!d[j]) {
            dfs(j,i);
            nc[i]+=nc[j];
        }
    }
}
int find_centroid(int i,int p,int n) {
    for (int j : a[i]) {
        if (j-p&&!d[j]&&nc[j]*2>n) {
            return find_centroid(j,i,n);
        }
    }
    return i;
}
void update(int x,int val) {
    for (;x<=mx;x+=(x&-x)) {
        bit[x]+=val;
    }
}
int ans(int x) {
    int res=0;
    for (;x;x&=(x-1)) {
        res+=bit[x];
    }
    return res;
}
void cal(int i,int p,int o,int ok) {
    mx=max(mx,o);
    if (!ok) {
        if (o>=l&&o<=r) {
            res++;
            res+=ans(min(ma,r-o));
        }
        else {
            if (ma+o>=l) {
                res+=(ll)(ans(min(r-o,ma))-ans(l-o-1));
            }
        }
    }
    if (ok==1) {
        ma=max(ma,o);
        update(o,1);
    }
    for (int j : a[i]) {
        if (j-p&&!d[j]&&o<r) {
            cal(j,i,o+1,ok);
        }
    }
}
void centroid(int i) {
    dfs(i,-1);
    int u=find_centroid(i,-1,nc[i]);
    d[u]=1;
    for (int j=1;j<=ma;j++) {
        bit[j]=0;
    }
    mx=0;
    for (int j : a[u]) {
        if (!d[j]) {
            cal(j,u,1,2);
        }
    }
    ma=0;
    for (int j : a[u]) {
        if (!d[j]) {
            cal(j,u,1,0);
            cal(j,u,1,1);
        }
    }
    for (int j : a[u]) {
        if (!d[j]) {
            centroid(j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>l>>r;
    for (int i=1;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    centroid(1);
    cout<<res;
}
