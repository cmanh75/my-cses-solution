#include<bits/stdc++.h>
using namespace std;
long long d,n,b[1000009],ans;
stack <long long> s;
set <long long> a;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>d>>n;
    for (int i=1;i<=n;i++) {
        cin>>b[i];
        a.insert(b[i]);
    }
    a.insert(0);
    a.insert(d);
    for (auto it=a.begin();it!=a.end();it++) {
        auto it1=it;
        it1++;
        ans=max(ans,*it1-*it);
    }
    s.push(ans);
    for (int i=n;i>=2;i--) {
        auto it=a.find(b[i]);
        auto it1=it;
        it1--;
        it++;
        ans=max(ans,*it-*it1);
        s.push(ans);
        it--;
        a.erase(*it);
    }
    while (s.size()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}
