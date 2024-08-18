#include<bits/stdc++.h>
using namespace std;
int n,q,pos[2000009],x,c,y,a[2000009];
long long it[2000009],pre[2000009],res,t;
void build(int i,int l,int r) {
    if (l==r) {
        it[i]=a[l];
        pre[i]=max(0,a[l]);
        pos[l]=i;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    it[i]=it[i*2]+it[i*2+1];
    pre[i]=max(pre[i*2],it[i*2]+pre[i*2+1]);
}
void update(int x,int y) {
    int i=pos[x];
    it[i]=y;
    pre[i]=max(0,y);
    i/=2;
    while (i) {
        it[i]=it[i*2]+it[i*2+1];
        pre[i]=max(pre[i*2],it[i*2]+pre[i*2+1]);
        i/=2;
    }
}
void ans(int i,int l,int r,int L,int R) {
    if (l>R||r<L) {
        return;
    }
    if (l>=L&&r<=R) {
        res=max(res,t+pre[i]);
        t+=it[i];
        return;
    }
    int mid=(l+r)/2;
    ans(i*2,l,mid,L,R);
    ans(i*2+1,mid+1,r,L,R);
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
    while(q--) {
        cin>>c>>x>>y;
        if (c==1) {
            update(x,y);
        }
        else {
            res=0;
            t=0;
            ans(1,1,n,x,y);
            cout<<res<<"\n";
        }
    }
}