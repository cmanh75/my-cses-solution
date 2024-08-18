#include<bits/stdc++.h>
using namespace std;
string s,x;
int n,to[1000009][28],o=0,la[1000009],f[1000009];
const int mod=1e9+7;
void addstr(string s) {
    int u=0;
    for (int i=0;i<s.size();i++) {
        if (!to[u][s[i]-'a']) {
            to[u][s[i]-'a']=++o;
        }
        u=to[u][s[i]-'a'];
    }
    la[u]=1;
}
int cal(int i) {
    if (f[i]+1) {
        return f[i];
    }
    if (i==s.size()) {
        return 1;
    }
    int u=0,ans=0;
    for (int j=i;j<s.size();j++) {
        if (!to[u][s[j]-'a']) {
            break;
        }
        u=to[u][s[j]-'a'];
        if (la[u]) {
            ans+=cal(j+1);
            ans%=mod;
        }
    }
    f[i]=ans;
    return f[i];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    memset(f,255,sizeof(f));
    cin>>s>>n;
    for (int i=1;i<=n;i++) {
        cin>>x;
        addstr(x);
    }
    cout<<cal(0);
}
