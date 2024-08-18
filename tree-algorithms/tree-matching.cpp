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
int n,dp[N][3];
vi a[N];
void dfs(int i,int p) {
    for (int j : a[i]) {
        if (j-p) {
            dfs(j,i);
            dp[i][0]+=dp[j][1];
        }
    }
    for (int j : a[i]) {
        if (j-p) {
            dp[i][1]=max(dp[i][1],dp[i][0]-dp[j][1]+1+dp[j][0]);
        }
    }
}
void solve() {
    cin>>n;
    for (int i=1;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,-1);
    cout<<max(dp[1][0],dp[1][1]);
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