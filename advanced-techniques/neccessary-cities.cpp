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
typedef vector<plii> vlii;
typedef vector<pli> vli;
typedef vector<ll> vl;
const int N=200005;
const int M=100005;
const int moh=1e9+3;
const ll mod=1e9+7;
const int base=311;
const int oi=1e9+1;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
char cc[]={'L','D','R','U'};
int mx[]={-2,2,2,-2,-1,1,-1,1};
int my[]={-1,1,-1,1,-2,2,2,-2};
int n,o=0,low[N],num[N],m,d[N];
vi a[N];
vii ans;
void dfs(int i,int pa) {
    low[i]=num[i]=++o;
    int cnt=0;
    for (int j : a[i]) {
        if (j-pa) {
            if (num[j]) {
                low[i]=min(low[i],num[j]);
            }
            else {
                dfs(j,i);
                cnt++;
                low[i]=min(low[i],low[j]);
                if (!pa) {
                    if (cnt>1) {
                        d[i]=1;
                    }
                }
                else {
                    if (low[j]>=num[i]) {
                        d[i]=1;
                    }
                }
            }
        }
    }
}
void solve() {
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for (int i=1;i<=n;i++) {
        if (!num[i]) {
            dfs(i,0);
        }
    }
    cout<<count(d+1,d+n+1,1)<<"\n";
    for (int i=1;i<=n;i++) {
        if (d[i]) {
            cout<<i<<" ";
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
