#include<bits/stdc++.h>
using namespace std;
int a[1000009],b[1000009],x,n;
bool ss(int i,int j) {
    return (a[i]<a[j]);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>x;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        b[i]=i;
    }
    sort(b+1,b+n+1,ss);
    sort(a+1,a+n+1);
    for (int i=1;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            int u=upper_bound(a+1,a+n+1,x-a[i]-a[j])-a;
            u--;
            if (u<=j) {
                break;
            }
            if (a[u]+a[i]+a[j]==x) {
                cout<<b[i]<<" "<<b[j]<<" "<<b[u];
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}
