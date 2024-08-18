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
const int N=100001;
const int M=1200000;
const int moh=1e9+3;
const ll mod=1e9+7;
const int base=311;
const int oi=2e9;
const ll oo=1e13;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int m,n,l[N],d[N],o;
vi a[N];
stack <int> st;
void dfs(int i) {
    if (d[i]==o) {
        int x;
        vi ans;
        ans.pb(i);
        do {
            x=st.top();
            st.pop();
            ans.pb(x);
        } while (x-i);
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<"\n";
        for (int j : ans) {
            cout<<j<<" ";
        }
        exit(0);
    }
    l[i]=1;
    st.push(i);
    d[i]=o;
    for (int j : a[i]) {
        if (!d[j]||(d[j]==o&&l[j])) {
            dfs(j);
        }
    }
    st.pop();
    l[i]=0;
}
void solve() {
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
    }
    for (int i=1;i<=n;i++) {
        if (!d[i]) {
            o++;
            dfs(i);
        }
    }
    cout<<"IMPOSSIBLE";
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
