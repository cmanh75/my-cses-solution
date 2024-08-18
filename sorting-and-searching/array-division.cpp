#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
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
typedef vector<piii> viii;
const int N=3e5+5;
const int M=2e5;
const ll mod=998244353;
const int moh=1e9+3;
const int base=311;
const int oi=2e9;
const ll oo=1e15;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,a[N],p;
bool check(ll x) {
    int res=0;
    ll s=0;
    for (int i=1;i<=n;i++) {
        if (a[i]>x) {
            return false;
        }
        if (s+a[i]>x) {
            res++;
            s=0;
        }
        s+=a[i];
    }
    return res+1<=p;
}
void solve() {
    cin>>n>>p;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    ll l=1,r=oo,ans;
    while (l<=r) {
        ll mid=(l+r)/2;
        if (check(mid)) {
            r=mid-1;
            ans=mid;
        }
        else {
            l=mid+1;
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
