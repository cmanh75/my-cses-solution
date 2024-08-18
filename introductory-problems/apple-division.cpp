#include<bits/stdc++.h>
using namespace std;
long long i,n,mx,t,a[1000009];
void tim(int i,long long s) {
    if (i==n+1) {
        mx=max(mx,s);
        return;
    }
    for (int j=0;j<=1;j++) {
        if (s+j*a[i]<=t/2) {
            tim(i+1,s+j*a[i]);
        }
    }
}
int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>a[i];
        t+=a[i];
    }
    tim(1,0);
    cout<<t-mx*2;
}
