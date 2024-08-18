#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int m,n,x,y;
ll dp[2000009][24];
const ll mod=1e9+7;
vector <int> a[100009];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        cin>>x>>y;
        a[x].push_back(y);
    }
    dp[1][1]=1;
    for (int i=1;i<(1<<n)-2;i++) {
        if (!(i&1)) {
            continue;
        }
        for (int j=1;j<=n;j++) {
            if (((i>>(j-1))&1)) {
                for (int k : a[j]) {
                    if (((i>>(k-1))&1)==0) {
                        dp[i|(1<<(k-1))][k]+=dp[i][j];
                        dp[i|(1<<(k-1))][k]%=mod;
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n];
}