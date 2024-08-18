#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,num[1000009],low[1000009],d[1000009],o;
vector <int> r,a[100009];
stack <int> st;
void dfs(int i) {
    st.push(i);
    num[i]=low[i]=++o;
    for (int j : a[i]) {
        if (!num[j]) {
            dfs(j);
        }
        low[i]=min(low[i],low[j]);
    }
    if (num[i]==low[i]) {
        r.push_back(i);
        int x;
        do {
            x=st.top();
            low[x]=1e9;
            st.pop();
        } while (x!=i);
    }
}
void dfs2(int i) {
    d[i]=1;
    for (int j : a[i]) {
        if (!d[j]) {
            dfs(j);
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
    }
    for (int i=1;i<=n;i++) {
        if (!num[i]) {
            dfs(i);
        }
    }
    if (r.size()==1) {
        cout<<"YES"<<"\n";
    }
    else {
        cout<<"NO"<<"\n";
        dfs(r[0]);
        if (d[r[1]]) {
            cout<<r[1]<<" "<<r[0];
        }
        else {
            cout<<r[0]<<" "<<r[1];
        }
    }
}
