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
int n,m,o,d[N],p,f[N];
vi a[N];
bool f_m(int i) {
    d[i]=o;
    for (int j : a[i]) {
        if (!f[j]) {
            f[j]=i;
            return true;
        }
        else {
            if (d[f[j]]-o&&f_m(f[j])) {
                f[j]=i;
                return true;
            }
        }
    }
    return false;
}
void solve() {
    cin>>m>>n>>p;
    for (int i=1;i<=p;i++) {
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
    }
    int ans=0;
    for (int i=1;i<=m;i++) {
        o++;
        if (f_m(i)) {
            ans++;
        }
    }
    cout<<ans<<"\n";
    for (int i=1;i<=n;i++) {
        if (f[i]) {
            cout<<f[i]<<" "<<i<<"\n";
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