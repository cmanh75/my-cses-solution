#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
set <int> s[400009];
int n,c[1000009],x,y,ans[1000009];
vector <int> a[1000009];
void dfs(int i,int p) {
    s[i].insert(c[i]);
    for (int j : a[i]) {
        if (j-p) {
            dfs(j,i);
            if (s[j].size()>s[i].size()) {
                swap(s[i],s[j]);
            }
            for (auto k : s[j]) {
                s[i].insert(k);
            }
        }
    }
    ans[i]=s[i].size();
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>c[i];
    }
    for (int i=1;i<n;i++) {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,-1);
    for (int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
}
