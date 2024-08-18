#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair <int,int> pii;
const int N=2000005;
const int oi=1e9;
const int mod=1e9+7;
int n,dp[N],a[N],x;
void solve() {
    cin>>n>>x;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    dp[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=a[i];j<=x;j++) {
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
    }
    cout<<dp[x];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int test=1;
    while (test--) {
        solve();
    }
}
