#include<bits/stdc++.h>
using namespace std;
long long i,n,m,x,u;
multiset <long long,greater<long long>> s;
int main() {
    cin>>m>>n;
    for (i=1;i<=m;i++) {
        cin>>x;
        s.insert(x);
    }
    for (i=1;i<=n;i++) {
        cin>>x;
        auto u=s.lower_bound(x);
        if (u==s.end()) {
            cout<<"-1\n";
            continue;
        }
        cout<<*u<<"\n";
        s.erase(u);
    }
}
