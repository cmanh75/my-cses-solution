#include<bits/stdc++.h>
using namespace std;
long long i,n,h,u,v,x,y,lab[1000009],m;
struct ii {
    int x,y;
};
vector <ii> ans;
int findset(int x) {
    return (lab[x]<0)?x:lab[x]=findset(lab[x]);
}
void combine(int x,int y) {
    if (lab[x]>lab[y]) {
        swap(x,y);
    }
    lab[x]+=lab[y];
    lab[y]=x;
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        lab[i]=-1;
    }
    for (int i=1;i<=m;i++) {
        cin>>x>>y;
        u=findset(x);
        v=findset(y);
        if (u!=v) {
            combine(u,v);
        }
    }
    for (int i=1;i<=n;i++) {
        if (lab[i]<0) {
            if (h==0) {
                h=i;
            }
            else {
                ii z = {h, i};
                ans.push_back(z);
                h=i;
            }
        }
    }
    cout<<ans.size()<<"\n";
    for (auto j : ans) {
        cout<<j.x<<" "<<j.y<<"\n";
    }
}
