#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,x,y,num[1000009],o;
vector <pii> ans;
vector <int> a[200009];
void dfs(int i) {
    num[i]=++o;
    for (int j : a[i]) {
        if (!num[j]) {
            dfs(j);
        }
        if (num[i]<num[j]) {
            ans.push_back({j,i});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i=1;i<=n;i++) {
        if (!num[i]) {
            dfs(i);
        }
    }
    for (auto [x,y] : ans) {
        cout<<x<<" "<<y<<"\n";
    }
}
