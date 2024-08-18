#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int m,n,a[1009],l[1009],ans;
char x;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        deque <int> qu;
        for (int j=1;j<=n;j++) {
            cin>>x;
            if (x=='*') {
                a[j]=0;
            }
            else {
                a[j]++;
            }
            while (qu.size()&&a[qu.back()]>=a[j]) {
                qu.pop_back();
            }
            if (qu.size()) {
                l[j]=qu.back();
            }
            else {
                l[j]=0;
            }
            qu.push_back(j);
        }
        qu.clear();
        for (int j=n;j>=1;j--) {
            while (qu.size()&&a[qu.back()]>=a[j]) {
                qu.pop_back();
            }
            if (qu.size()) {
                ans=max(ans,(qu.back()-l[j]-1)*a[j]);
            }
            else {
                ans=max(ans,(n-l[j])*a[j]);
            }
            qu.push_back(j);
        }
    }
    cout<<ans;
}
