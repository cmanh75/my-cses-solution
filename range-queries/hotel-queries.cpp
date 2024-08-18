#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000009],t[5000009],x,pos[5000009],o;
void build(int i,int l,int r) {
    o=max(o,i);
    if (l==r) {
        t[i]=a[l];
        pos[i]=l;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    t[i]=max(t[i*2],t[i*2+1]);
}
int ans(int x) {
    int i=1;
    do {
        if (t[i*2]>=x) {
            i*=2;
        }
        else {
            i=i*2+1;
        }
    } while (t[i]);
    return i/2;
}
void update(int cs,int z) {
    t[cs]-=z;
    while (cs!=1) {
        cs/=2;
        t[cs]=max(t[cs*2],t[cs*2+1]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    build(1,1,n);
    for (int i=1;i<=m;i++) {
        cin>>x;
        if (t[1]>=x) {
            int r=ans(x);
            cout<<pos[r]<<" ";
            update(r,x);
        }
        else {
            cout<<"0 ";
        }
    }
}
