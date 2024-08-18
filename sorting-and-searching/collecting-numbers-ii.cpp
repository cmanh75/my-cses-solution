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
const int oi=1e9;
const ll oo=1e15;
const double eps=1e-9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={-1,0,1,0,-1,1,-1,1};
int n,pos[N],a[N],m;
void solve() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        pos[a[i]]=i;
    }
    int ans=1,last=0;
    for (int i=1;i<=n;i++) {
        if (pos[i]<last) {
            ans++;
        }
        last=pos[i];
    }
    while (m--) {
        int x,y;
        cin>>x>>y;
        if (x>y) {
            swap(x,y);
        }
        if (a[y]==a[x]+1||a[x]==a[y]+1) {
            if (a[x]==a[y]+1) {
                ans--;
                if (x<pos[a[y]-1]&&pos[a[y]]>pos[a[y]-1]) {
                    ans++;
                }
                if (y>pos[a[x]+1]&&pos[a[x]]<pos[a[x]+1]) {
                    ans++;
                }
            }
            else {
                ans++;
                if (x<pos[a[y]+1]&&pos[a[y]]>pos[a[y]+1]) {
                    ans--;
                }
                if (y>pos[a[x]-1]&&pos[a[x]]<pos[a[x]-1]) {
                    ans--;
                }
            }
        }
        else {
            if (x<pos[a[y]+1]&&pos[a[y]]>pos[a[y]+1]) {
                ans--;
            }
            if (x<pos[a[y]-1]&&pos[a[y]]>pos[a[y]-1]) {
                ans++;
            }
            if (y>pos[a[x]-1]&&pos[a[x]]<pos[a[x]-1]) {
                ans--;
            }
            if (y>pos[a[x]+1]&&pos[a[x]]<pos[a[x]+1]) {
                ans++;
            }
        }
        swap(a[x],a[y]);
        swap(pos[a[x]],pos[a[y]]);
        cout<<ans<<"\n";
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
