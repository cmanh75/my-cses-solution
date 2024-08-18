#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int x,n,k,ans=1e9;
vector <int> s;
char c;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        int x=0;
        for (int j=1;j<=k;j++) {
            cin>>c;
            x<<=1;
            if (c=='1') {
                x++;
            }
        }
        s.push_back(x);
    }
    for (int i=0;i<s.size();i++) {
        for (int j=i+1;j<s.size();j++) {
            ans=min(ans,__builtin_popcount(s[i]^s[j]));
        }
    }
    cout<<ans;
}
