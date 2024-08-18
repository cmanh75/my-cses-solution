#include<bits/stdc++.h>
using namespace std;
int x,n,ans,d[1000009],l[1000009];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>x;
        for (int j=1;j<=sqrt(x);j++) {
            if (x%j==0) {
                if (d[x/j]) {
                    ans=max(ans,x/j);
                    break;
                }
                if (d[j]) {
                    ans=max(ans,j);
                }
                d[j]++;
                d[x/j]++;
            }
        }
    }
    cout<<ans;
}