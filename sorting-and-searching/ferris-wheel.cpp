#include<bits/stdc++.h>
using namespace std;
long long i,n,w,a[1000009],ans,j;
int main() {
    cin>>n>>w;
    for (i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    i=1;j=n;
    while (i<=j) {
        if (a[i]+a[j]>w) {
            ans++;
            j--;
        }
        else {
            i++;
            j--;
            ans++;
        }
    }
    cout<<ans;
}
