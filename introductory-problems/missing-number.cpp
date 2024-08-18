#include<bits/stdc++.h>
using namespace std;
long long i,n,x,d[1000000];
int main() {
    cin>>n;
    for (i=1;i<n;i++) {
        cin>>x;
        d[x]=1;
    }
    for (i=1;i<=n;i++) {
        if (d[i]==0) {
            cout<<i;
            return 0;
        }
    }
}
