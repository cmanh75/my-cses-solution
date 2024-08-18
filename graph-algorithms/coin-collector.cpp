#include<bits/stdc++.h>
using namespace std;
long long n,m,low[1000009],num[1000009],p[1000009],r[1000009],o,u,ans[1000009],res,val[1000009],b[1000009],c[1000009];
stack <int> st;
vector <int> a[1000009],aa[1000009];
void tarjan(int i) {
    num[i]=low[i]=++o;
    st.push(i);
    for (int j : a[i]) {
        if (!num[j]) {
            tarjan(j);
        }
        low[i]=min(low[i],low[j]);
    }
    if (low[i]==num[i]) {
        int x;
        u++;
        do {
            x=st.top();
            st.pop();
            low[x]=1e9;
            p[x]=u;
            r[u]+=val[x];
        } while (x!=i);
    }
}
void dfs(int i) {
    ans[i]=r[i];
    for (int j : aa[i]) {
        if (!ans[j]) {
            dfs(j);
        }
        ans[i]=max(ans[i],ans[j]+r[i]);
    }
    res=max(ans[i],res);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>val[i];
    }
    for (int i=1;i<=m;i++) {
        cin>>b[i]>>c[i];
        a[b[i]].push_back(c[i]);
    }
    for (int i=1;i<=n;i++) {
        if (!num[i]) {
            tarjan(i);
        }
    }
    for (int i=1;i<=m;i++) {
         if (p[b[i]]!=p[c[i]]) {
            aa[p[b[i]]].push_back(p[c[i]]);
         }
    }
    for (int i=1;i<=u;i++) {
        if (!ans[i]) {
            dfs(i);
        }
    }
    cout<<res;
}