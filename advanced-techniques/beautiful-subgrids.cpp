#pragma GCC target("popcnt")
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
const int N=3e3+1;
const int mod=998244353;
const int moh=1e9+3;
const int base=311;
const int oi=2e9;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n;
bitset <N> r[N];
void solve() {
    cin>>n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            char c;
            cin>>c;
            if (c=='1') {
                r[i].set(j);
            }
        }
    }
    ll ans=0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            int x=(r[i]&r[j]).count();
            ans+=(ll)(x-1)*x/2;
        }
    }
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
