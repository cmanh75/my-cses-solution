#include<bits/stdc++.h>
using namespace std;
int n,last[1000009][4];
string s,ans;
char c[4]={'A','C','G','T'};
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>s;
    n=s.size();
    s=" "+s;
    last[n+1][0]=n+1;
    last[n+1][1]=n+1;
    last[n+1][2]=n+1;
    last[n+1][3]=n+1;
    for (int i=n;i>=0;i--) {
        for (int j=0;j<4;j++) {
            last[i][j]=last[i+1][j];
            if (s[i+1]==c[j]) {
                last[i][j]=i+1;
            }
        }
    }
    int i=0;
    while (i<=n) {
        int u=0,z;
        for (int j=0;j<4;j++) {
            if (u<last[i][j]) {
                u=last[i][j];
                z=j;
            }
        }
        ans+=c[z];
        i=u;
    }
    cout<<ans;
}
