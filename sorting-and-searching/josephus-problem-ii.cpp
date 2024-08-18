#include<bits/stdc++.h>
using namespace std;
int n,k,bit[2000009],cr;
void update(int x,int val) {
    for (;x<=2*n;x+=(x&-x)) {
        bit[x]+=val;
    }
}
int ans(int x) {
    if (!x) {
        return 0;
    }
    int res=0;
    for (;x>0;x&=(x-1)) {
        res+=bit[x];
    }
    return res;
}
bool check(long long z,int cs) {
    return (z/n*cr+ans(cs+z%n)-ans(cs)>=k);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>k;
    k++;
    for (int i=1;i<=n;i++) {
        update(i,1);
        update(i+n,1);
    }
    int cs=0;
    cr=n;
    for (int i=1;i<=n;i++) {
        long long l=1,r=1e15,res;
        while (l<=r) {
            long long mid=(l+r)/2;
            if (check(mid,cs)) {
                res=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        cs=(cs+res%n)%n;
        if (!cs) {
            cs=n;
        }
        cr--;
        update(cs,-1);
        update(cs+n,-1);
        cout<<cs<<" ";
    }
}
