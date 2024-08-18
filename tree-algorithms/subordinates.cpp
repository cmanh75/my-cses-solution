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
int n,nc[N];
vi a[N];
void dfs(int i,int p) {
    nc[i]=1;
    for (int j : a[i]) {
        if (j-p) {
            dfs(j,i);
            nc[i]+=nc[j];
        }
    }
}
void solve() {
    cin>>n;
    for (int i=2;i<=n;i++) {
        int x;
        cin>>x;
        a[x].push_back(i);
        a[i].push_back(x);
    }
    dfs(1,-1);
    for (int i=1;i<=n;i++) {
        cout<<nc[i]-1<<" ";
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