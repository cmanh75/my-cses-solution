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
    cin>>n;
    for (int i=0;i<n;i++) {
        dp[i]=oi;
    }
    for (int i=n;i>0;i--) {
        int x=i;
        while (x) {
            int u=x%10;
            dp[i-u]=min(dp[i]+1,dp[i-u]);
            x/=10;
        }
    }
    cout<<dp[0];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int test=1;
    while (test--) {
        solve();
    }
}
