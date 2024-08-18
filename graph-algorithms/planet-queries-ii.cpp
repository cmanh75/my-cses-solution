#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
const int N=2e5+9;
const int mod=1e9+7;
const int moh=1e9+5;
const int base=311;
const int oi=2e9;
const ll oo=1e18;
const double eps=1e-9;
int n,m,tel[N],rt[N],o=0,con[N],root[N],dp[N],ci[N],q,z,in[N],out[N];
vector <int> a[N];
void dfs(int i,int p) {
    con[i]=o;
    in[i]=++z;
    if (root[i]) {
        p=i;
        rt[i]=i;
    }
    for (int j : a[i]) {
        if (!con[j]) {
            rt[j]=p;
            dp[j]=dp[i]+1;
            dfs(j,p);
        }
    }
    out[i]=++z;
}
void process(int i) {
    int x=tel[i],y=tel[x];
    o++;
    while (x-y) {
        x=tel[x];
        y=tel[tel[y]];
    }
    x=i;
    while (x-y) {
        x=tel[x];
        y=tel[y];
    }
    do {
        y=tel[y];
        ci[o]++;
        root[y]=1;
    } while (x-y);
    dfs(x,-1);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>tel[i];
        a[tel[i]].push_back(i);
    }
    for (int i=1;i<=n;i++) {
        if (!con[i]) {
            process(i);
        }
    }
    while (q--) {
        int x,y;
        cin>>x>>y;
        if (con[x]-con[y]) {
            cout<<"-1"<<"\n";
        }
        else {
            if (root[y]) {
                int ans=dp[x]-dp[rt[x]];
                x=rt[x];
                if (dp[x]>=dp[y]) {
                    ans+=dp[x]-dp[y];
                }
                else {
                    ans+=ci[con[x]]-dp[y]+dp[x];
                }
                cout<<ans<<"\n";
            }
            else {
                if (rt[x]==rt[y]&&in[x]>=in[y]&&out[x]<=out[y]) {
                    cout<<dp[x]-dp[y]<<"\n";
                }
                else {
                    cout<<"-1"<<"\n";
                }
            }
        }
    }
}
