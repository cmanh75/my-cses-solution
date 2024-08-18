#include<bits/stdc++.h>
using namespace std;
long long x,y,n,c,val,a[1000009],t[1000009],lazy[1000009],q;
void down(int i) {
    t[i]+=lazy[i];
    lazy[i*2]+=lazy[i];
    lazy[i*2+1]+=lazy[i];
    lazy[i]=0;
}
void build(int i,int l,int r) {
    if (l==r) {
        t[i]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    t[i]=t[i*2]+t[i*2+1];
}
void update(int i,int l,int r,int L,int R,int val) {
    down(i);
    if (l>R||r<L) {
        return;
    }
    if (l>=L&&r<=R) {
        lazy[i]=val;
        down(i);
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,L,R,val);
    update(i*2+1,mid+1,r,L,R,val);
    t[i]=t[i*2]+t[i*2+1];
}
long long ans(int i,int l,int r,int L,int R) {
    down(i);
    if (l>R||r<L) {
        return 0;
    }
    if (l>=L&&r<=R) {
        return t[i];
    }
    int mid=(l+r)/2;
    return (ans(i*2,l,mid,L,R)+ans(i*2+1,mid+1,r,L,R));
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    build(1,1,n);
    while (q--) {
        cin>>c>>x;
        if (c==1) {
            cin>>y>>val;
            update(1,1,n,x,y,val);
        }
        else {
            cout<<ans(1,1,n,x,x)<<"\n";
        }
    }
}