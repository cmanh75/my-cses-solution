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
typedef vector<plii> vlii;
typedef vector<pli> vli;
typedef vector<ll> vl;
const int N=1005;
const int M=3000005;
const int moh=1e9+3;
const ll mod=1e9+7;
const int base=311;
const int oi=1e9+1;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={1,0,0,-1,1,1,-1,-1};
int dy[]={0,1,-1,0,-1,1,-1,1};
int n,m,d[N][N];
pii l[N][N];
char a[N][N];
queue <pii> qu;
void trace(int x,int y) {
    stack <char> st;
    while (l[x][y].fi) {
        int r=x,s=y;
        x=l[x][y].fi;
        y=l[r][y].se;
        if (x==r+1) {
            st.push('U');
        }
        if (x==r-1) {
            st.push('D');
        }
        if (y==s-1) {
            st.push('R');
        }
        if (y==s+1) {
            st.push('L');
        }
    }
    cout<<"YES"<<"\n";
    cout<<st.size()<<"\n";
    while (st.size()) {
        cout<<st.top();
        st.pop();
    }
}
void solve() {
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            if (a[i][j]=='M') {
                qu.push(mp(i,j));
                d[i][j]=1;
            }
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]=='A') {
                qu.push(mp(i,j));
                d[i][j]=2;
            }
        }
    }
    while (qu.size()) {
        auto [x,y]=qu.front();
        qu.pop();
        if (d[x][y]==2&&(x==1||y==1||x==m||y==n)) {
            trace(x,y);
            return;
        }
        for (int i=0;i<4;i++) {
            int u=x+dx[i];
            int v=y+dy[i];
            if (!d[u][v]&&u&&v&&u<=m&&v<=n&&a[u][v]!='#') {
                d[u][v]=d[x][y];
                l[u][v]=mp(x,y);
                qu.push(mp(u,v));
            }
        }
    }
    cout<<"NO";
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
