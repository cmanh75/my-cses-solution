#include<bits/stdc++.h>
using namespace std;
long long n,m,f[1000009],p[1000009],q;
void solve(long long n) {
    int i;
    for (i=0;i<=100;i++) {
        if (f[i+1]>n) {
            break;
        }
    }
    if (f[i]==n) {
        cout<<"9"<<"\n";
        return;
    }
    long long u=p[i]+(n-f[i])/(i+1),r=(n-f[i])%(i+1);
    if (r==0) {
        cout<<(u-1)%10<<"\n";
    }
    else {
        cout<<(u/(p[i+1-r]))%10<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>q;
    p[0]=1;
    for (int i=1;i<=18;i++) {
        p[i]=p[i-1]*10;
    }
    for (int i=1;i<=100;i++) {
        f[i]=f[i-1]+(p[i]-p[i-1])*i;
        if (f[i]>1e18) {
            break;
        }
//        cout<<f[i]<<"\n";
    }
    while (q--) {
        cin>>n;
        solve(n);
    }
}
