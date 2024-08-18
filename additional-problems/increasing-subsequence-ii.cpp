#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
int n,x,res,bit[1000009],a[1000009];
vector <pii> s;
void update(int x,int val) {
    for (;x<=n;x+=(x&-x)) {
        bit[x]+=val;
        bit[x]%=mod;
    }
}
int ans(int x) {
    int res=0;
    for (;x;x&=(x-1)) {
        res+=bit[x];
        res%=mod;
    }
    return res;
}
bool cmp(pii m,pii n) {
    return m.fi<n.fi;
}
bool cmp1(pii m,pii n) {
    return m.se<n.se;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        s.push_back({a[i],i});
    }
    sort(s.begin(),s.end(),cmp);
    int o=1,cs=0;
    for (int i=1;i<s.size();i++) {
        if (s[i].fi-s[i-1].fi) {
            for (int j=cs;j<i;j++) {
                s[j].fi=o;
            }
            o++;
            cs=i;
        }
    }
    for (int i=cs;i<s.size();i++) {
        s[i].fi=o;
    }
    sort(s.begin(),s.end(),cmp1);
    for (auto [x,y] : s) {
        int z=ans(x-1);
        res+=z+1;
        res%=mod;
        update(x,z+1);
    }
    cout<<res;
}
