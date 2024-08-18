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
int n,m,p;
vii a[N];
priority_queue <pli,vli,greater<pli>> pq;
ll d[N][12];
void solve() {
    cin>>n>>m>>p;
    for (int i=1;i<=m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[x].pb(mp(y,z));
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=p;j++) {
            d[i][j]=oo;
        }
    }
    d[1][1]=0;
    pq.push(mp(0,1));
    while (pq.size()) {
        pli x=pq.top();
        pq.pop();
        if (d[x.se][p]<x.fi) {
            continue;
        }
        for (pii j : a[x.se]) {
            if (d[j.fi][p]>x.fi+j.se) {
                pq.push(mp(x.fi+j.se,j.fi));
                for (int i=1;i<=p;i++) {
                    if (d[j.fi][i]>x.fi+j.se) {
                        for (int k=p;k>i;k--) {
                            d[j.fi][k]=d[j.fi][k-1];
                        }
                        d[j.fi][i]=x.fi+j.se;
                        break;
                    }
                }
            }
        }
    }
    for (int i=1;i<=p;i++) {
        cout<<d[n][i]<<" ";
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
