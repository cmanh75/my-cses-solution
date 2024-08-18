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
const int N=3e5+5;
const int M=3e5;
const ll mod=1e9+7;
const int moh=1e9+3;
const int base=311;
const int oi=1e9;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,ans[N],ma[N],ms[N];
vi a[N];
void dfs(int i,int pa) {
    ma[i]=ms[i]=0;
    for (int j : a[i]) {
        if (j-pa) {
            dfs(j,i);
            if (ma[j]+1>ma[i]) {
                ms[i]=ma[i];
                ma[i]=ma[j]+1;
            }
            else {
                ms[i]=max(ms[i],ma[j]+1);
            }
        }
    }
}
void cal(int i,int pa,int d) {
    ans[i]=max(ma[i],d);
    for (int j : a[i]) {
        if (j-pa) {
            if (ma[i]==ma[j]+1) {
                cal(j,i,1+max(d,ms[i]));
            }
            else {
                cal(j,i,1+max(d,ma[i]));
            }
        }
    }
}
void solve() {
    cin>>n;
    for (int i=1;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,-1);
    cal(1,-1,0);
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
