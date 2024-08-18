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
int n,ans[N],p,a[N];
void solve() {
    cin>>n>>p;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    priority_queue <pii> pqi;
    priority_queue <pii,vii,greater<pii>> pqa;
    int k=(p+1)/2,j=0;
    for (int i=1;i<=n;i++) {
        if (i>p&&pqi.size()&&a[i-p]<=pqi.top().fi) {
            j--;
        }
        if (j<k) {
            pqa.push(mp(a[i],i));
            pqi.push(pqa.top());
            pqa.pop();
            j++;
        }
        else {
            pqi.push(mp(a[i],i));
            pqa.push(pqi.top());
            pqi.pop();
        }
        while (pqi.size()&&pqi.top().se<=i-p) {
            pqi.pop();
        }
        while (pqa.size()&&pqa.top().se<=i-p) {
            pqa.pop();
        }
        if (i>=p) {
            ans[i]=pqi.top().fi;
        }
    }
    for (int i=p;i<=n;i++) {
        cout<<ans[i]<<" ";
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
