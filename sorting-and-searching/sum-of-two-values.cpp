#include<bits/stdc++.h>
using namespace std;
#define ii pair<long long ,long long>
#define x first
#define y second
long long i,n,l,r,x,u,k;
ii a[1000009];
bool ss(ii i,ii j) {
    return i.x<j.x;
}
int main() {
    cin>>n>>k;
    for (i=1;i<=n;i++) {
        cin>>a[i].x;
        a[i].y=i;
    }
    sort(a+1,a+n+1,ss);
    for (i=1;i<=n;i++) {
        l=i+1;
        r=n;
        while (l<=r) {
            int mid=(l+r)/2;
            if (a[mid].x>k-a[i].x) {
                r=mid-1;
                continue;
            }
            if (a[mid].x<k-a[i].x) {
                l=mid+1;
                continue;
            }
            cout<<a[i].y<<" "<<a[mid].y;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
}
