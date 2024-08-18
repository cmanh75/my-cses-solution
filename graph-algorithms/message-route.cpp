#include<bits/stdc++.h>
using namespace std;
long long m,n,d[1000009],t[1000009],x,y;
vector <long long> a[1000009];
struct ii {
    int x,y;
};
queue <ii> q;
stack<int> s;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        d[i]=1e9;
    }
    for (int i=1;i<=m;i++) {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    d[1]=1;
    q.push({1,1});
    while (q.size()) {
        int x=q.front().x,y=q.front().y;
        q.pop();
        if (d[x]!=y) {
            continue;
        }
        for (int j : a[x]) {
            if (d[j]>d[x]+1) {
                d[j]=d[x]+1;
                t[j]=x;
                ii z = {j, d[j]};
                q.push(z);
            }
        }
    }
    if (d[n]==1e9) {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<d[n]<<"\n";
    while (n!=1) {
        s.push(n);
        n=t[n];
    }
    s.push(1);
    while (s.size()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}
