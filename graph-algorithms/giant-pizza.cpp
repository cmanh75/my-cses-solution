#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
const int N=2e5+9;
const int oi=2e9;
const int base=311;
const ll oo=1e18;
const ll mod=1e9+7;
const ll moh=1e9+3;
const double eps=1e-9;
int n,val[N*2],low[N*2],num[N*2],con[N*2],o,m;
vi a[N*2];
stack <int> st;
void push(int x,int y) {
    a[x^1].push_back(y);
    a[y^1].push_back(x);
}
void tarjan(int i) {
    st.push(i);
    low[i]=num[i]=++o;
    for (int &j : a[i]) {
        if (!num[j]) {
            tarjan(j);
        }
        low[i]=min(low[i],low[j]);
    }
    if (num[i]==low[i]) {
        int x;
        do {
            x=st.top();
            st.pop();
            low[x]=oi;
            con[x]=i+1;
            if (val[x/2]==-1) {
                val[x/2]=!(x&1);
            }
        } while (x-i);
    }
}
void solve() {
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        int xa,xb;
        char ca,cb;
        cin>>ca>>xa>>cb>>xb;
        xa=(xa-1)*2+(ca=='-');
        xb=(xb-1)*2+(cb=='-');
        push(xa,xb);
    }
    memset(val,255,sizeof(val));
    for (int i=0;i<2*n;i++) {
        if (!num[i]) {
            tarjan(i);
        }
    }
    for (int i=0;i<n;i++) {
        if (con[i*2]==con[i*2+1]) {
            cout<<"IMPOSSIBLE";
            return;
        }
    }
    for (int i=0;i<n;i++) {
        cout<<(val[i]?"+":"-")<<" ";
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
