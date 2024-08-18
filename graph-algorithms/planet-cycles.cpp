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
typedef vector<piii> viii;
typedef vector<pli> vli;
typedef vector<ll> vl;
const int N=200005;
const int M=4000001;
const int moh=1e9+3;
const ll mod=1e9+7;
const int base=311;
const int oi=2e9;
const ll oo=1e13;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,p,d[N],low[N],num[N],dp[N],b[N],g[N],o,e;
vi s[N],a[N];
stack <int> st;
void dfs(int i) {
    low[i]=num[i]=++o;
    st.push(i);
    for (int j : a[i]) {
        if (!num[j]) {
            dfs(j);
        }
        low[i]=min(low[i],low[j]);
    }
    if (num[i]==low[i]) {
        int x;
        e++;
        do {
            x=st.top();
            st.pop();
            low[x]=oi;
            g[e]++;
            d[x]=e;
        } while (x-i);
    }
}
void cal(int i) {
    dp[i]=g[i];
    for (int j : s[i]) {
        if (!dp[j]) {
            cal(j);
        }
        dp[i]=dp[j]+1;
    }
}
void solve() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        b[i]=x;
        a[i].pb(x);
    }
    for (int i=1;i<=n;i++) {
        if (!num[i]) {
            dfs(i);
        }
    }
    for (int i=1;i<=n;i++) {
        if (d[i]-d[b[i]]) {
            s[d[i]].pb(d[b[i]]);
        }
    }
    for (int i=1;i<=e;i++) {
        if (!dp[i]) {
            cal(i);
        }
    }
    for (int i=1;i<=n;i++) {
        cout<<dp[d[i]]<<" ";
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
