#include<bits/stdc++.h>
using namespace std;
long long n,a[1000009],e,b[1000009],c[1000009];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    e=1;
    b[1]=a[1];
    c[1]=1;
    cout<<"0"<<" ";
    for (int i=2;i<=n;i++) {
        int u=lower_bound(b+1,b+e+1,a[i])-b;
        cout<<c[u-1]<<" ";
        if (u>e) {
            e++;
        }
        else {
            e=u;
        }
        b[u]=a[i];
        c[u]=i;
    }
}