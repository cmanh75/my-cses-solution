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
typedef pair<ll,ll> pll;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<piii> viii;
const int N=5e3+5;
const int M=2e5;
const ll mod=998244353;
const int moh=1e9+3;
const int base=311;
const int oi=1e9;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,a[N];
ll dp[N][N][3];
void solve() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        dp[i][i][0]=a[i];
    }
    for (int i=n;i>0;i--) {
        for (int j=i+1;j<=n;j++) {
            dp[i][j][0]=max(dp[i+1][j][1]+a[i],dp[i][j-1][1]+a[j]);
            dp[i][j][1]=min(dp[i+1][j][0],dp[i][j-1][0]);
        }
    }
    cout<<dp[1][n][0];
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
