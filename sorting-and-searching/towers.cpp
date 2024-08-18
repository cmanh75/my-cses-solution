#include<bits/stdc++.h>
using namespace std;
long long a[1000009],b[1000009],e;
int np(long long x) {
    int l=1,r=e,ans=e+1;
    while (l<=r) {
        int mid=(l+r)/2;
        if (b[mid]<=x) {
            l=mid+1;
        }
        else {
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    e=1;
    b[e]=a[1];
    for (int i=2;i<=n;i++) {
        int u=np(a[i]);
        b[u]=a[i];
        if (u==e+1) {
            e++;
        }
    }
    cout<<e;
}
