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
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
const int N=200005;
const int oi=1e9;
const ll oo=1e18;
int n,a[N],l;
void solve() {
    cin>>l>>n;
    priority_queue <ll,vl,greater<ll>> pq;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        pq.push(a[i]);
    }
    ll ans=0;
    while (pq.size()>1) {
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        ans+=x+y;
        pq.push(x+y);
    }
    cout<<ans;
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
