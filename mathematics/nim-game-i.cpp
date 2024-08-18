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
const int moh=1e9+3;
const int base=311;
const int oi=2e9;
const ll oo=1e18;
int n;
ll x;
void solve() {
    cin>>n;
    ll s=0;
    for (int i=1;i<=n;i++) {
        cin>>x;
        s^=x;
    }
    if (!s) {
        cout<<"second"<<"\n";
    }
    else {
        cout<<"first"<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    int test;
    cin>>test;
    while (test--) {
        solve();
    }
}
