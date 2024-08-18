#include<bits/stdc++.h>
using namespace std;
int n,p,x[100009],d[1000009],s;
void cal() {
    for (int j=1;j<=n;j++) {
        cout<<x[j];
    }
    cout<<"\n";
    int t;
    for (int j=1;j<=n;j++) {
        if (x[j]==0) {
            x[j]=1;
            t=s;
            s|=(1<<(j-1));
            if (!d[s]) {
                d[s]=1;
                cal();
            }
            s=t;
            x[j]=0;
        }
        else {
            x[j]=0;
            t=s;
            s-=(1<<(j-1));
            if (!d[s]) {
                d[s]=1;
                cal();
            }
            s=t;
            x[j]=1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    d[0]=1;
    cal();
}
