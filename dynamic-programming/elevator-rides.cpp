#include<bits/stdc++.h>
#define pa pair <int,int>
#define fi first
#define se second
using namespace std;
int n,m,w[100];
pa a[1100009];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>w[i];
    }
    a[0]={0,m};
    for (int i=1;i<=(1<<n)-1;i++) {
        a[i]={25,0};
        for (int j=0;j<n;j++) {
            if ((i>>j)&1) {
                int r=i^(1<<j),x,y;
                tie(x,y)=a[r];
                if (y+w[j+1]>m) {
                    a[i]=min(a[i],{x+1,w[j+1]});
                }
                else {
                    a[i]=min(a[i],{x,y+w[j+1]});
                }
            }
        }
    }
    cout<<a[(1<<n)-1].fi;
}
