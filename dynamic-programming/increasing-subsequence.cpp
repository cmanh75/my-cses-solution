#include<bits/stdc++.h>
using namespace std;
int n,a[1000009],b[1000009],ans;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int e=1;
    b[e]=a[1];
    for (int i=2;i<=n;i++) {
        int u=lower_bound(b+1,b+e+1,a[i])-b;
        if (u>e) {
            e++;
        }
        b[u]=a[i];
    }
    cout<<e;
}
