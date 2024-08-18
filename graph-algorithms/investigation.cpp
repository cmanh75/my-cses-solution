#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
const int N=2e5+5;
const int M=2e5;
const ll mod=1e9+7;
const int moh=1e9+3;
const int base=311;
const int oi=1e9;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,m,ma[N],mi[N];
priority_queue <pli,vli,greater<pli>> pq;
ll d[N],l[N];
vii a[N];
void solve() {
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[x].pb(mp(y,z));
    }
    for (int i=1;i<=n;i++) {
        d[i]=oo;
    }
    d[1]=0;
    pq.push(mp(0,1));
    l[1]=1;
    while (pq.size()) {
        pli x=pq.top();
        pq.pop();
        if (x.fi-d[x.se]) {
            continue;
        }
        for (pii j : a[x.se]) {
            if (d[j.fi]>d[x.se]+j.se) {
                d[j.fi]=d[x.se]+j.se;
                l[j.fi]=l[x.se];
                ma[j.fi]=ma[x.se]+1;
                mi[j.fi]=mi[x.se]+1;
                pq.push(mp(d[j.fi],j.fi));
            }
            else {
                if (d[j.fi]==d[x.se]+j.se) {
                    l[j.fi]=(l[j.fi]+l[x.se])%mod;
                    ma[j.fi]=max(ma[j.fi],ma[x.se]+1);
                    mi[j.fi]=min(mi[j.fi],mi[x.se]+1);
                }
            }
        }
    }
    cout<<d[n]<<" "<<l[n]<<" "<<mi[n]<<" "<<ma[n];
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