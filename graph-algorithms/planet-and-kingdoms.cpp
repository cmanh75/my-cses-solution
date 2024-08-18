#include<bits/stdc++.h>
using namespace std;
int n,m,ans,d[1000009],x,y,low[1000009],num[1000009],o;
vector <int> a[100009];
stack <int> st;
void dfs(int i) {
    st.push(i);
    num[i]=low[i]=++o;
    for (int j : a[i]) {
        if (!num[j]) {
            dfs(j);
        }
        low[i]=min(low[j],low[i]);
    }
    if (num[i]==low[i]) {
        ans++;
        int x;
        do {
            x=st.top();
            d[x]=ans;
            low[x]=1e9;
            st.pop();
        } while (x!=i);
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
    }
    for (int i=1;i<=n;i++) {
        if (!num[i]) {
            dfs(i);
        }
    }
    cout<<ans<<"\n";;
    for (int i=1;i<=n;i++) {
        cout<<d[i]<<" ";
    }
}