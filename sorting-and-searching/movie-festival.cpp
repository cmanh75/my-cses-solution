#include<bits/stdc++.h>
using namespace std;
#define ii pair <long long,long long>
#define x first
#define y second
long long i,n,d,ans,m,p,q,u;
vector <ii> a;
int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>p>>q;
        a.push_back({q,p});
    }
    sort(a.begin(),a.end());
    for (i=0;i<a.size();i++) {
        if (a[i].y>=d) {
            ans++;
            d=a[i].x;
        }
    }
    cout<<ans;
}
