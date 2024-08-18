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
typedef vector<int> vi;
typedef vector<pii> vii;
const int N=200005;
const int M=1200005;
const int oi=1e9;
const ll oo=1e18;
int n,a[N],p;
ll ans[N];
void solve() {
    cin>>n>>p;
    priority_queue <pii> pqi;
    priority_queue <pii,vii,greater<pii>> pqa;
    int k=(p+1)/2,j=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    ll s=0,t=0;
    for (int i=1;i<=n;i++) {
        if (i>p) {
            if (a[i-p]<=pqi.top().fi) {
                j--;
                s-=a[i-p];
            }
            else {
                t-=a[i-p];
            }
        }
        if (j<k) {
            pqa.push(mp(a[i],i));
            t+=a[i];
            pqi.push(pqa.top());
            t-=pqa.top().fi;
            s+=pqa.top().fi;
            pqa.pop();
            j++;
        }
        else {
            pqi.push(mp(a[i],i));
            s+=a[i];
            pqa.push(pqi.top());
            s-=pqi.top().fi;
            t+=pqi.top().fi;
            pqi.pop();
        }
        while (pqa.size()&&pqa.top().se<=i-p) {
            pqa.pop();
        }
        while (pqi.size()&&pqi.top().se<=i-p) {
            pqi.pop();
        }
        ans[i]=1ll*pqi.top().fi*k-s+t-1ll*pqi.top().fi*(p-k);
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
