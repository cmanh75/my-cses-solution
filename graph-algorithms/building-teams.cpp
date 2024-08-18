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
const int N=300005;
const int M=3000005;
const int moh=1e9+3;
const ll mod=1e9+7;
const int base=311;
const int oi=1e9+1;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={1,0,0,-1,1,1,-1,-1};
int dy[]={0,1,-1,0,-1,1,-1,1};
int n,c[N],m;
vi a[N];
void dfs(int i,int color) {
    c[i]=color;
    for (int j : a[i]) {
        if (!c[j]) {
            dfs(j,3-color);
        }
        else {
            if (c[j]==color) {
                cout<<"IMPOSSIBLE"<<"\n";
                exit(0);
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
        if (!c[i]) {
            dfs(i,1);
        }
    }
    for (int i=1;i<=n;i++) {
        cout<<c[i]<<" ";
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